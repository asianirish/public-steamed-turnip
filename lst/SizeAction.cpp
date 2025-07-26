#include "SizeAction.h"

namespace turnip {
namespace cmd {

using namespace def;

namespace lst {

SizeAction::SizeAction() {}

def::ActionDef SizeAction::actionDef() const
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

Value SizeAction::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    auto lst = args.at(0).toList();

    return static_cast<int64_t>(lst.size());
}

} // namespace lst
} // namespace cmd
} // namespace turnip
