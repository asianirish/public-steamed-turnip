#include "CommonComposer.h"
#include "cmd/CompositeAction.h"
#include "cmd/Context.h"
#include "cmd/PrintAction.h"
#include "cmd/ForAction.h"

#include "common/HumanStringGenerator.h"
#include "math/AddAction.h"
#include "math/Eq.h"
#include "math/Less.h"
#include "math/LogicalOrAction.h"
#include "math/Inc.h"

using namespace turnip::cmd::math;

namespace turnip {
namespace cmd {

ActionPtr CommonComposer::lessOrEqual()
{
    auto ca = mkDynActionPtr(CompositeAction);

    const auto typeDef = def::TypeDef::createIntTypedef(); // TODO: double?

    def::ActionDef actionDef;
    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("left");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("right");
        actionDef.addArgDef(argDef);
    }

    auto context = Context::create();
    context->setStringGen(mkPtr<common::HumanStringGenerator>());
    auto lessAlias = context->registerValue(mkActionPtr(LessInt), "less");
    auto eqAlias = context->registerValue(mkActionPtr(EqInt), "eq");

    actionDef.setDescription("Less Or Equal");
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(LogicalOrAction));
    ca->addParams(ParamList({
        Parameter(lessAlias, ParamList({0_pos, 1_pos})),
        Parameter(eqAlias, ParamList({0_pos, 1_pos})),
    }));

    return ca;
}

CommonComposer::CommonComposer() {}

} // namespace cmd
} // namespace turnip
