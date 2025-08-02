#include "BatchNumber.h"
#include <cmath>

namespace turnip {
namespace cmd {

using namespace def;

BatchNumber::BatchNumber() {}

def::ActionDef BatchNumber::actionDef() const
{
    ActionDef actionDef;

    actionDef.setDescription("Batch Number");

    const auto intDef = TypeDef::createIntTypedef();

    {
        ArgDef argDef;
        argDef.setName("batchSize");
        argDef.setType(intDef);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setName("arrSize");
        argDef.setType(intDef);
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value BatchNumber::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;
    auto batchSize = args.at(0).toInt();
    auto arrSize = args.at(1).toInt();

    return std::ceil(static_cast<double>(arrSize) / batchSize);
}

} // namespace cmd
} // namespace turnip
