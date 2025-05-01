#include "PersonArgToMapAction.h"

namespace turnip {
namespace cmd {

using namespace def;

PersonArgToMapAction::PersonArgToMapAction() {}

def::ActionDef PersonArgToMapAction::actionDef() const
{
    ActionDef actionDef;

    const auto stringTypeDef = TypeDef::createStringTypedef();
    const auto intTypeDef = TypeDef::createIntTypedef();
    const auto charTypeDef = TypeDef::createCharTypedef();

    {
        ArgDef argDef;
        argDef.setType(stringTypeDef);
        argDef.setName("name");
        argDef.setDesc("Person's Name");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(intTypeDef);
        argDef.setName("year");
        argDef.setDesc("Year of birth");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(charTypeDef); // TODO: constraint: 'm' or 'f'
        argDef.setName("gender");
        argDef.setDesc("Person's Gender");
        actionDef.addArgDef(argDef);
    }

    // TODO: return map

    actionDef.setDescription("Arg To Map");

    return actionDef;
}

Value PersonArgToMapAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    auto name = args.at(0).toString();
    auto year = args.at(1).toInt();
    auto gender = args.at(2).toChar();

    VariantMap mp;
    mp.set("name", name);
    mp.set("year", year);
    mp.set("gender", gender);

    return mp;
}

} // namespace cmd
} // namespace turnip
