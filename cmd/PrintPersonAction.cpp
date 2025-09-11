#include "PrintPersonAction.h"
#include "cmd/def/IntRangeConstraint.h"
#include "cmd/def/ListConstraint.h"

#include <chrono>
#include <ctime>

int64_t currentYear() {
    // Get the current time as a time_point
    auto now = std::chrono::system_clock::now();

    // Convert time_point to time_t to get calendar time
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert time_t to a tm struct
    std::tm* localTime = std::localtime(&currentTime);

    // Extract the current year from the tm struct and adjust for tm_year starting from 1900
    return localTime->tm_year + 1900;
}

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

        auto con = mkPtr<IntRangeConstraint>(IntRangeConstraint(currentYear() - 39, currentYear() - 18));
        argDef.setConstraint(con);

        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(charTypeDef); // TODO: constraint: 'm' or 'f'
        argDef.setName("gender");
        argDef.setDesc("Person's Gender");

        auto con = mkPtr<ListConstraint>(ListConstraint{'m', 'f'});
        argDef.setConstraint(con);

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
    std::cout << "Age: " << (currentYear() - year) << std::endl;
    std::cout << "Gender: " << gender << std::endl;

    return true;
}

} // namespace cmd
} // namespace turnip
