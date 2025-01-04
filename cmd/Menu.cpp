#include "Menu.h"
#include "cmd/HelpAction.h"
#include "cmd/TaskManager.h"

namespace turnip {
namespace cmd {

Menu::Menu() : helpAction_(ACTION_CLASS(HelpAction)) {

}

LazyAction Menu::registerAction(const std::string &commandName, const Value &actionInfo)
{
    auto data = actionInfo.data();

    LazyAction retAction;

    std::string *pClassName = std::get_if<std::string>(&data);
    LazyAction *actionPtrPtr = std::get_if<LazyAction>(&data);

    if (pClassName) {
        auto className = *pClassName;
        LazyAction action(className);
        actions_.insert({commandName, action});
        retAction = action;

    } else if (actionPtrPtr) {
        auto actionPtr = *actionPtrPtr;
        actions_.insert({commandName, actionPtr});
        retAction = actionPtr;
    } // TODO: handle map

    {
        auto f = std::bind(&Menu::onTaskComplete, this, std::placeholders::_1);
        taskManager_.setCallback(f);
    }

    {
        auto f = std::bind(&Menu::onTaskError, this, std::placeholders::_1);
        taskManager_.setErrorCallback(f);
    }

    {
        auto f = std::bind(&Menu::onTaskStart, this, std::placeholders::_1);
        taskManager_.setStartCallback(f);
    }

    return retAction;
}

void Menu::registerHelpAction()
{
    auto actionPtr = helpAction_.ptr();
    auto helpPtr = std::dynamic_pointer_cast<HelpAction>(actionPtr);
    helpPtr->setMenu(this);
    actions_.insert({"help", helpAction_});
}

const std::list<std::string> &Menu::commandList() const
{
    commandList_.clear();

    for (auto &pr : actions_) {
        commandList_.push_back(pr.first);
    }
    return commandList_;
}

void Menu::processString(const std::string &input)
{
    if (translator_) {
        Info info = translator_->translate(input);
        executeAction(info.command(), info.args());
    }
}

void Menu::executeAction(const std::string &command, const InputArgList &args)
{
    bool ok = false;
    auto a = action(command, &ok);

    if (ok) {
        taskManager_.execute(a, args);
    }
}

std::shared_ptr<Translator> Menu::translator() const
{
    return translator_;
}

void Menu::setTranslator(const std::shared_ptr<Translator> &newTranslator)
{
    translator_ = newTranslator;
}

TaskManager Menu::taskManager() const
{
    return taskManager_;
}

void Menu::setResultCallback(const ResultCallback &newResultCallback)
{
    resultCallback_ = newResultCallback;
}

void Menu::setErrorCallback(const ErrorCallback &newErrorCallback)
{
    errorCallback_ = newErrorCallback;
}

def::ActionDef Menu::actionDef(const std::string &command) const
{
    bool ok = false;
    auto a = action(command, &ok);
    if (ok) {
        return a->actionDef();
    }

    return {};
}

std::string Menu::name() const
{
    return name_;
}

void Menu::setName(const std::string &newMenuName)
{
    name_ = newMenuName;
}

void Menu::setStartCallback(const StartCallback &newStartCallback)
{
    startCallback_ = newStartCallback;
}

void Menu::onTaskComplete(const Result &result)
{
    if (resultCallback_) {
        resultCallback_(result);
    }
}

void Menu::onTaskError(const err::Error &error)
{
    if (errorCallback_) {
        errorCallback_(error.description());
    }
}

void Menu::onTaskStart(const TaskId &taskId)
{
    if (startCallback_) {
        startCallback_(taskId);
    }
}

ActionPtr Menu::action(const std::string &command, bool *ok) const
{
    if (ok) {
        *ok = false;
    }
#if __cplusplus >= 202002L
    if (!actions_.contains(command)) {
#else
    if (actions_.find(command) == actions_.end()) {
#endif
        errorCallback_("Menu error: Command '" + command + "' was not found.");
        return nullptr;
    }

    if (ok) {
        *ok = true;
    }
    return actions_.at(command).ptr();
}


} // namespace cmd
} // namespace turnip
