#include "PrintAction.h"

namespace turnip {
namespace cmd {

PrintAction::PrintAction() {}

def::ActionDef PrintAction::actionDef() const
{
    // TODO: implement
    return def::ActionDef();
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
