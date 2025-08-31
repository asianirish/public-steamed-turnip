#include "DoNothing.h"

namespace turnip {
namespace cmd {

using namespace def;

const int DoNothing::MAX_DEFAULT_ARGUMENTS = 20;

DoNothing::DoNothing() {}

def::ActionDef DoNothing::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();

    for (int i = 0; i < MAX_DEFAULT_ARGUMENTS; ++i) {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue(std::string());
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Doing nothing");

    auto boolRep = mkPtr<BoolRep>(BoolRep::Kind::OnOff);
    actionDef.setResultRepresentation(boolRep);

    return actionDef;
}

Value DoNothing::actImpl(const ArgList &args, err::Error &error)
{
    (void) error;

    std::cout << "DO NOTHING\n";

    if (!args.size()) {
        return false;
    }

    if (args.at(0).toString().empty()) {
        return false;
    }

    return true;
}

} // namespace cmd
} // namespace turnip
