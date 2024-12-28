#include "MenuAction.h"
#include "cmd/LineTranslator.h"
#include "console/Reader.h"

namespace turnip {
namespace cmd {

MenuAction::MenuAction() {
    menu_.registerHelpAction();
}

def::ActionDef MenuAction::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription(menu_.name() + " menu");
    return actionDef;
}

void MenuAction::setMenuName(const std::string &menuName)
{
    menu_.setName(menuName);
}

void MenuAction::addAction(const std::string &commandName, const Value &actionInfo)
{
    menu_.registerAction(commandName, actionInfo);
}

Value MenuAction::actImpl(const ArgList &args, err::Error &error)
{
    (void)args;
    (void)error;

    // TODO: check whether translator is set

    console::Reader reader(menu_.name(), menu_.commandList());
    reader.setIsMain(false);
    std::string historyFileName {"." + menu_.name() + ".command-history"};
    reader.setHistoryFileName(historyFileName);

    {
        auto f = std::bind(&cmd::Menu::processString, &menu_, std::placeholders::_1);
        reader.setCallback(f);
    }

    {
        auto f = std::bind(&console::Reader::onResult, &reader, std::placeholders::_1);
        menu_.setResultCallback(f);
    }

    {
        auto f = std::bind(&console::Reader::onError, &reader, std::placeholders::_1);
        menu_.setErrorCallback(f);
    }

    {
        auto f = std::bind(&console::Reader::onTaskStart, &reader, std::placeholders::_1);
        menu_.setStartCallback(f);
    }

    reader.read();

    return true;
}

void MenuAction::setTranslator(const std::shared_ptr<cmd::Translator> &newTrnsl)
{
    menu_.setTranslator(newTrnsl);
}

} // namespace cmd
} // namespace turnip
