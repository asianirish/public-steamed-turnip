#include "BatchCount.h"

#include <cmath> // for std::ceil

namespace turnip {
namespace cmd {

using namespace def;

namespace lst {

BatchCount::BatchCount() {}

def::ActionDef BatchCount::actionDef() const
{
    ActionDef actionDef;

    actionDef.setDescription("Batch Count of Args");

    const auto intDef = TypeDef::createIntTypedef();
    const auto lstDef = TypeDef::createStringTypedef(); // TODO: createListTypedef();

    {
        ArgDef argDef;
        argDef.setName("batchSize");
        argDef.setType(intDef);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setName("arr");
        argDef.setType(lstDef);
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value BatchCount::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;
    auto batchSize = args.at(0).toInt();
    auto listSize = args.at(1).toList();

    return std::ceil(static_cast<double>(listSize.size()) / batchSize);
}

} // namespace lst
} // namespace cmd
} // namespace turnip
