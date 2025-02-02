#include "CountingAction.h"
#include "cmd/rep/SimpleStringRep.h"

namespace turnip {
namespace cmd {

using namespace def;

CountingAction::CountingAction() {}

def::ActionDef CountingAction::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    actionDef.addArgDef(argDef);


    auto strRep = std::make_shared<SimpleStringRep>();
    actionDef.setResultRepresentation(strRep);
    actionDef.setDescription("Outputs the specified string");

    return actionDef;
}

Value CountingAction::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;
    static int counter = 0;
    auto str = args.at(0).toString();

    std::cout << counter << ". " << str << std::endl;
    ++counter;

    return str;
}

} // namespace cmd
} // namespace turnip
