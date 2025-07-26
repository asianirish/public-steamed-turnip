#include "Batch.h"

namespace turnip {
namespace cmd {

using namespace def;

namespace lst {

Batch::Batch() {}

def::ActionDef Batch::actionDef() const
{
    ActionDef actionDef;

    actionDef.setDescription("At");

    const auto intDef = TypeDef::createIntTypedef();

    {
        ArgDef argDef;
        argDef.setName("batchIndex");
        argDef.setType(intDef);
        actionDef.addArgDef(argDef);
    }
    {
        ArgDef argDef;
        argDef.setName("batchSize");
        argDef.setType(intDef);
        actionDef.addArgDef(argDef);
    }


    {
        const auto strDef = TypeDef::createStringTypedef(); // TODO: createListTypedef
        ArgDef argDef;
        argDef.setName("arr");
        argDef.setType(strDef);
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value Batch::actImpl(const ArgList &args, err::Error &error)
{
    auto index = args.at(0).toInt();
    auto size = args.at(1).toInt();
    auto arr = args.at(2).toList();

    if (index * size >= static_cast<int64_t>(arr.size())) {
        error = err::Error::createCustomError("Out of range error");
        return {};
    }

    VariantList result;
    for (auto i = index * size; i < index * size + size; ++i) {
        if (i >= static_cast<int64_t>(arr.size())) {
            break;
        }
        auto val = arr.get(i);
        result.push_back(val);
    }

    return result;
}

} // namespace lst
} // namespace cmd
} // namespace turnip
