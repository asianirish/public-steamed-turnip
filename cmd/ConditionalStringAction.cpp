#include "ConditionalStringAction.h"

namespace turnip {
namespace cmd {

using namespace def;

ConditionalStringAction::ConditionalStringAction() {}

def::ActionDef ConditionalStringAction::actionDef() const
{
    ActionDef actionDef;

    const auto boolTypeDef = TypeDef::createBoolTypedef();
    const auto strTypeDef = TypeDef::createStringTypedef();
    {
        ArgDef condArgDef;
        condArgDef.setType(boolTypeDef);
        condArgDef.setName("condition");
        actionDef.addArgDef(condArgDef);
    }

    {
        ArgDef firstStrArgDef;
        firstStrArgDef.setType(strTypeDef);
        firstStrArgDef.setName("firstString");
        actionDef.addArgDef(firstStrArgDef);
    }

    {
        ArgDef secondStrArgDef;
        secondStrArgDef.setType(strTypeDef);
        secondStrArgDef.setName("secondString");
        actionDef.addArgDef(secondStrArgDef);
    }

    actionDef.setDescription("Conditional string");

    return actionDef;
}

Value ConditionalStringAction::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;
    bool yes = args.at(0);

    if (yes) {
        return args.at(1);
    }

    return args.at(2);
}

} // namespace cmd
} // namespace turnip
