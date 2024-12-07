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

Value HelpAction::actImpl(const ArgList &args)
{
    std::cout << std::endl << std::endl;

    if (menu_) {

        std::string commandName = args.at(0);
        std::cout << "NAME:" << std::endl;
        std::cout << "\t" << commandName << std::endl;
        auto def = menu_->actionDef(commandName);
        std::cout << "DESCRIPTION:" << std::endl;
        std::cout << "\t" << def.description() << std::endl;

        std::cout << "ARGUMENTS:" << std::endl;
        auto argList = def.argDefs();
        int i = 0;
        for (auto &argDef : argList) {
            std::cout << "\t[" << i << "] "  << argDef.name() << std::endl; // TODO: output type info
            ++i;
        }

        return true;
    }

    return false; // TODO: logical error
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
