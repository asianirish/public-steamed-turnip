#include "SineOfRadians.h"
#include <cmath>

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

SineOfRadians::SineOfRadians() {}

def::ActionDef SineOfRadians::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createDoubleTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    argDef.setName("radians");
    actionDef.addArgDef(argDef);

    actionDef.setDescription("Calculates the sine of a specified angle measured in radians");

    return actionDef;
}

Value SineOfRadians::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;

    double radians = args.at(0);
    return std::sin(radians);
}

} // namespace math
} // namespace cmd
} // namespace turnip
