#include "Menu.h"
#include "cmd/TaskManager.h"

namespace turnip {
namespace cmd {

Menu::Menu() {}

void Menu::registerCommand(const std::string &commandName, const Value &actionInfo)
{
    commands_.insert({commandName, actionInfo});
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
        ArgList argList;

        execute(info.command(), info.args());
    }
}

void Menu::execute(const std::string &command, const InputArgList &args)
{
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


} // namespace cmd
} // namespace turnip
