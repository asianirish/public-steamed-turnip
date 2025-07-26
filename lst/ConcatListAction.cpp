#include "ConcatListAction.h"

namespace turnip {
namespace cmd {
namespace lst {

using namespace def;

ConcatListAction::ConcatListAction() {}

def::ActionDef ConcatListAction::actionDef() const
{
    ActionDef actionDef;

    const auto strDef = TypeDef::createStringTypedef(); // TODO: createListTypedef

    actionDef.setDescription("Concat List Action");

    ArgDef argDef;
    argDef.setType(strDef);
    argDef.setDefaultValue("");
    actionDef.addArgDef(argDef);

    return actionDef;
}

Value ConcatListAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    std::string result;

    auto lst = args.at(0).toList();

    for (auto &arg : lst) {
        if (arg.isNull()) {
            break;
        }

        if (arg.toString().empty()) {
            break;
        }

        result += arg.toString();
    }

    return result;
}

} // namespace lst
} // namespace cmd
} // namespace turnip
