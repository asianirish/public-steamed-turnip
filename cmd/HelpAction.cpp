#include "HelpAction.h"

namespace turnip {
namespace cmd {

using namespace def;

HelpAction::HelpAction() {}

def::ActionDef HelpAction::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    argDef.setName("commandName");
    actionDef.addArgDef(argDef);

    actionDef.setDescription("Displays information about a specified command");

    return actionDef;
}

Value HelpAction::actImpl(const ArgList &args, err::Error &error)
{
    std::cout << std::endl << std::endl;

    if (menu_) {

        std::string commandName = args.at(0);

        if (commandName == "menu" || commandName == "ls") {
            std::cout << "Display the list of available commands" << std::endl;
            return true;
        }

        if (commandName == "quit") {
            std::cout << "Stop the current command input loop and return control to the previous routine" << std::endl;
            return true;
        }

        if (commandName == "exit") {
            std::cout << "Terminate the application immediately and close the session" << std::endl;
            return true;
        }


        auto def = menu_->actionDef(commandName);

        if (!def) {
            error.setDescription("Help error: Definition for command '" + commandName + "' was not found");
            return {};
        }

        std::cout << "NAME:" << std::endl;
        std::cout << "\t" << commandName << std::endl;
        std::cout << "DESCRIPTION:" << std::endl;
        std::cout << "\t" << def.description() << std::endl;

        auto argList = def.argDefs();

        if (!argList.empty()) {
            std::cout << "ARGUMENTS:" << std::endl;
            int i = 0;
            for (auto &argDef : argList) {
                std::cout << "\t[" << i << "] (" << argDef.type().inputRep() << ") "  << argDef.name();
                if (!argDef.defaultValue().isNull()) {
                    std::cout << " = " << argDef.defaultValue();
                }
                std::cout << std::endl; // TODO: output type info
                ++i;
            }
        }

        return true;
    }

    error.setDescription("menu is not set");
    return {};
}

Menu *HelpAction::menu() const
{
    return menu_;
}

void HelpAction::setMenu(Menu *newMenu)
{
    menu_ = newMenu;
}

} // namespace cmd
} // namespace turnip
