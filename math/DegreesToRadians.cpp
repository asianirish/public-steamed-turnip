#include "DegreesToRadians.h"
#include <cmath>

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

DegreesToRadians::DegreesToRadians() {}

def::ActionDef DegreesToRadians::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createDoubleTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    argDef.setName("degrees");
    actionDef.addArgDef(argDef);

    actionDef.setDescription("Converts the degree representation of an angle to radians");

    return actionDef;
}

Value DegreesToRadians::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;

    double degrees = args.at(0);
    return degrees * (M_PI / 180.0);
}

} // namespace math
} // namespace cmd
} // namespace turnip
