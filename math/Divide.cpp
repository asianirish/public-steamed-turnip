#include "Divide.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

Divide::Divide() {}

def::ActionDef Divide::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createDoubleTypedef();

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

    actionDef.setDescription("Divides two numbers");
    auto doubleRep = std::make_shared<DoubleRep>();
    actionDef.setResultRepresentation(doubleRep);

    return actionDef;
}

Value Divide::actImpl(const ArgList &args, err::Error &error)
{
    if (args.at(1).toDouble() == 0) {
        error.maybeSetDescription("Division by zero");
        return {};
    }

    return args.at(0).toDouble()/args.at(1).toDouble();
}

} // namespace math
} // namespace cmd
} // namespace turnip
