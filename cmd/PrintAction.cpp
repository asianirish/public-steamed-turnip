#include "PrintAction.h"
// #include <thread>

#include <unistd.h>

namespace turnip {
namespace cmd {

using namespace def;

PrintAction::PrintAction() {}

def::ActionDef PrintAction::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    actionDef.addArgDef(argDef);

    return actionDef;
}

Value PrintAction::actImpl(const ArgList &args)
{
    std::cout << "\nPrintAction" << std::endl;
    for (auto &arg : args) {
        std::cout << arg << std::endl;
    }

    return true;
}

} // namespace cmd
} // namespace turnip
