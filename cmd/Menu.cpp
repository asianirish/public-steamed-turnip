#include "Menu.h"
#include "cmd/TaskManager.h"

namespace turnip {
namespace cmd {

Menu::Menu() {}

void Menu::registerAction(const std::string &commandName, const Value &actionInfo)
{
    auto data = actionInfo.data();

    std::string *pClassName = std::get_if<std::string>(&data);

    if (pClassName) {
        auto className = *pClassName;
        LazyAction action(className);
        actions_.insert({commandName, action});

    } // TODO: handle map

    {
        auto f = std::bind(&Menu::onTaskComplete, this, std::placeholders::_1);
        taskManager_.setCallback(f);
    }

    {
        auto f = std::bind(&Menu::onTaskError, this, std::placeholders::_1);
        taskManager_.setErrorCallback(f);
    }
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
#if __cplusplus >= 202002L
    if (!actions_.contains(command)) {
#else
    if (actions_.find(command) == actions_.end()) {
#endif
        errorCallback_("Command '" + command + "' not found.");
        return;
    }
    auto action = actions_.at(command);
    taskManager_.execute(action, args);
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

void Menu::onTaskComplete(const Value &result)
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


} // namespace cmd
} // namespace turnip
