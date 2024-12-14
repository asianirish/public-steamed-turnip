#include "IsEven.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

IsEven::IsEven() {}

def::ActionDef IsEven::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createIntTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    actionDef.addArgDef(argDef);

    actionDef.setDescription("Determines if the given number is even");

    return actionDef;
}

Value IsEven::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;

    int64_t n = args.at(0);
    return ((n % 2) == 0);
}

} // namespace math
} // namespace cmd
} // namespace turnip
