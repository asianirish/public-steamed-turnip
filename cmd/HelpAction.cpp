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
    std::cout << "\nHelp Action" << std::endl;

    // TODO: implement
    std::cout << args.at(0) << std::endl;

    return true;
}

} // namespace cmd
} // namespace turnip
