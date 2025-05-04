#include "HowLongSince.h"

#include <chrono>

namespace turnip {
namespace cmd {

using namespace def;

HowLongSince::HowLongSince() {}

def::ActionDef HowLongSince::actionDef() const
{
    ActionDef actionDef;

    const auto intDef = TypeDef::createIntTypedef();

    {
        ArgDef argDef;
        argDef.setType(intDef);
        argDef.setName("year");
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value HowLongSince::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;
    int givenYear = args.at(0).toInt();

    auto currentTime = std::chrono::system_clock::now();
    auto currentTimeInTimeT = std::chrono::system_clock::to_time_t(currentTime);
    tm* currentTimeTm = std::localtime(&currentTimeInTimeT);

    int currentYear = currentTimeTm->tm_year + 1900;

    int yearsSinceGivenYear = currentYear - givenYear;

    return yearsSinceGivenYear;

}

} // namespace cmd
} // namespace turnip
