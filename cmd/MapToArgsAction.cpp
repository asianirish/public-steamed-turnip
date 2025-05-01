#include "MapToArgsAction.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

using namespace def;

MapToArgsAction::MapToArgsAction() {}

def::ActionDef MapToArgsAction::actionDef() const
{
    ActionDef actionDef;

    const auto strDef = TypeDef::createStringTypedef(); // TODO: createActionTypedef and createMapTypedef

    actionDef.setDescription("Map To Argument List");

    {
        ArgDef argDef;
        argDef.setType(strDef);
        argDef.setName("action");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(strDef);
        argDef.setName("map");
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value MapToArgsAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;
    TaskPtr taskPtr(new Task());

    ActionPtr childActionPtr = args.at(0).toActionPtr();
    taskPtr->setActionPtr(childActionPtr);
    auto childActionDef = childActionPtr->actionDef();
    auto childArgDefs = childActionDef.argDefs();

    VariantMap argMap = args.at(1).toMap();
    ArgList argList;
    argList.reserve(argMap.size());

    for (const auto &childArgDef : childArgDefs) {
        auto argName = childArgDef.name();
        if (argMap.contains(argName)) {
            auto arg = argMap.get(argName);
            argList.push_back(arg);
        }
    }

    taskPtr->setArgList(argList);

    return taskPtr;
}

} // namespace cmd
} // namespace turnip
