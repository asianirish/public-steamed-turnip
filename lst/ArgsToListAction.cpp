#include "ArgsToListAction.h"
#include "cmd/Const.h"

namespace turnip {
namespace cmd {
namespace lst {

using namespace def;

ArgsToListAction::ArgsToListAction() {}

def::ActionDef ArgsToListAction::actionDef() const
{
    ActionDef actionDef;

    const auto strDef = TypeDef::createStringTypedef();

    actionDef.setDescription("Args to List Action");

    for (size_t i = 0; i < Const::ARG_MAX; ++i)
    {
        ArgDef argDef;
        argDef.setType(strDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value ArgsToListAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    VariantList lst;

    for (auto &arg : args) {
        if (arg.isNull()) {
            break;
        }

        if (arg.toString().empty()) {
            break;
        }

        lst.push_back(arg);
    }

    return lst;
}


} // namespace lst
} // namespace cmd
} // namespace turnip
