#include "ListToArgsAction.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {
namespace lst {

using namespace def;

ListToArgsAction::ListToArgsAction() {}

def::ActionDef ListToArgsAction::actionDef() const
{
    ActionDef actionDef;

    const auto strDef = TypeDef::createStringTypedef(); // TODO: createActionTypedef and createListTypedef

    actionDef.setDescription("List To Argument List");

    {
        ArgDef argDef;
        argDef.setType(strDef);
        argDef.setName("action");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(strDef);
        argDef.setName("list");
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value ListToArgsAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;
    TaskPtr taskPtr(new Task());

    ActionPtr childActionPtr = args.at(0).toActionPtr();
    taskPtr->setActionPtr(childActionPtr);

    ArgList argList = args.at(1).toList().toStdVector();
    taskPtr->setArgList(argList);

    return taskPtr;
}

} // namespace lst
} // namespace cmd
} // namespace turnip
