#include "Menu.h"
#include "cmd/TaskManager.h"

namespace turnip {
namespace cmd {

Menu::Menu() {}

void Menu::registerCommand(const std::string &commandName, const Value &actionInfo)
{
    commands_.insert({commandName, actionInfo});

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

    for (auto &pr : commands_) {
        commandList_.push_back(pr.first);
    }
    return commandList_;
}

void Menu::processString(const std::string &input)
{
    if (translator_) {
        Info info = translator_->translate(input);
        execute(info.command(), info.args());
    }
}

void Menu::execute(const std::string &command, const InputArgList &args)
{
    if (!commands_.contains(command)) {
        errorCallback_("Command '" + command + "' not found.");
        return;
    }
    auto actionDesc = commands_.at(command);
    taskManager_.execute(actionDesc, args);
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
