#include "PrintPersonAction.h"

namespace turnip {
namespace cmd {

using namespace def;

PrintPersonAction::PrintPersonAction() {}

def::ActionDef PrintPersonAction::actionDef() const
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


    actionDef.setDescription("Print Person");

    return actionDef;
}

Value PrintPersonAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    auto name = args.at(0).toString();
    auto year = args.at(1).toInt();
    auto gender = args.at(2).toChar();

    std::cout  << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Year of birth: " << year << std::endl;
    std::cout << "Gender: " << gender << std::endl;

    return true;
}

} // namespace cmd
} // namespace turnip
