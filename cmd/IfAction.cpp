#include "IfAction.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

using namespace def;

IfAction::IfAction() {}

def::ActionDef IfAction::actionDef() const
{
    ActionDef actionDef;

    const auto boolDef = TypeDef::createBoolTypedef();
    // const auto taskDef = TypeDef::createTaskTypedef(); // TODO: implement Task TypeDef

    ArgDef argDef;
    argDef.setType(boolDef);
    actionDef.addArgDef(argDef);

    // TODO: implement

    return actionDef;
}

Value IfAction::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;

    bool yes = args.at(0);

    if (yes) {
        return args.at(1).toTaskPtr();
    }

    return args.at(2).toTaskPtr();
}

} // namespace cmd
} // namespace turnip
