#include "Composer.h"
#include "cmd/CompositeAction.h"
#include "math/DegreesToRadians.h"
#include "math/Divide.h"
#include "math/SineOfRadians.h"

namespace turnip {
namespace cmd {

using namespace def;

namespace math {

Composer::Composer() {}

ActionPtr Composer::reverseDivide()
{
    auto caRvrs = mkDynActionPtr(CompositeAction);

    ActionDef actionDef;

    const auto typeDef = def::TypeDef::createDoubleTypedef();

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("left number");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("right number");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Reverse Divide");
    actionDef.setResultRepresentation(mkRepPtr(DoubleRep));
    caRvrs->setActionDef(actionDef);

    //---

    caRvrs->setAction(mkActionPtr(Divide));
    caRvrs->addParams(ParamList({1, 0}));

    return caRvrs;
}

ActionPtr Composer::sineOfDegrees()
{
    auto caSind = mkDynActionPtr(CompositeAction);

    ActionDef actionDef;

    const auto typeDef = TypeDef::createDoubleTypedef();

    ArgDef argDef;
    argDef.setType(typeDef);
    argDef.setName("degrees");
    actionDef.addArgDef(argDef);
    actionDef.setDescription("Calculates the sine of a specified angle measured in degrees");

    actionDef.setResultRepresentation(mkRepPtr(DoubleRep));

    caSind->setActionDef(actionDef);

    //---

    // caSind->setSubstitutor(sbst);
    caSind->setAction(mkActionPtr(SineOfRadians));
    caSind->addParam(mkActionPtr(DegreesToRadians), ParamList({0}));

    return caSind;
}

} // namespace math
} // namespace cmd
} // namespace turnip
