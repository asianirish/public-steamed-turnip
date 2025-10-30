#include "PrintAction.h"

#include <iostream>
#include <unistd.h>

namespace turnip {
namespace cmd {

using namespace def;

std::mutex PrintAction::mutex_;

PrintAction::PrintAction() {}

def::ActionDef PrintAction::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);

    actionDef.addArgDef(argDef);

    actionDef.setDescription("Outputs the specified string");

    return actionDef;
}

Value PrintAction::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;

    auto firstStr = args.at(0).toString();
    if (firstStr.empty()) {
        return false;
    }

    sleep(1);
    auto arg = args.at(0);

#ifdef DEBUG_MULPIPLE_PRINT
    for (int i = 0; i < 100000; ++i) {
        mutex_.lock();
        for (int j = 0; j < 20; ++j) {
            std::cout << arg;
        }
        std::cout << std::endl;
        mutex_.unlock();

    }
#else
    std::cout << arg;
    std::cout.flush();
#endif

    return true;
}

} // namespace cmd
} // namespace turnip
