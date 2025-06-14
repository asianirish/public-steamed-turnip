#include "First.h"

namespace turnip {
namespace cmd {

using namespace def;

First::First() {}

def::ActionDef First::actionDef() const
{
    ActionDef actionDef;
    actionDef.setDescription("Returns First Argument");
    const auto typeDef = TypeDef::createStringTypedef();

    {
        ArgDef argDef;
        argDef.setName("first");
        argDef.setType(typeDef);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setName("second");
        argDef.setType(typeDef);
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value First::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    return args.at(0);
}

} // namespace cmd
} // namespace turnip
