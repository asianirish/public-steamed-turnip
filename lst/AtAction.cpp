#include "AtAction.h"

namespace turnip {
namespace cmd {

using namespace def;

namespace lst {

AtAction::AtAction() {}

def::ActionDef AtAction::actionDef() const
{
    ActionDef actionDef;

    actionDef.setDescription("At");

    {
        const auto intDef = TypeDef::createIntTypedef();
        ArgDef argDef;
        argDef.setName("index");
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

Value AtAction::actImpl(const ArgList &args, err::Error &error)
{
    auto index = args.at(0).toInt();
    auto lst = args.at(1).toList();

    if (index >= static_cast<int64_t>(lst.size())) {
        error = err::Error::createCustomError("Out of range error");
        return {};
    }

    return lst.get(index);
}

} // namespace lst
} // namespace cmd
} // namespace turnip
