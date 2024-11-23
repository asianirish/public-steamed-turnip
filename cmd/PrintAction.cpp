#include "PrintAction.h"
// #include <thread>

#include <unistd.h>

namespace turnip {
namespace cmd {

using namespace def;

PrintAction::PrintAction() {}

def::ActionDef PrintAction::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();
    ArgDef argDef;
    argDef.setType(typeDef);
    actionDef.addArgDef(argDef);

    return actionDef;
}

Value PrintAction::actImpl(const ArgList &args)
{
    std::cout << "\nPrintAction" << std::endl;

    sleep(20);
    // using namespace std::chrono_literals;
    // std::this_thread::sleep_for(20s);

    for (int i = 0; i < 100000000; ++i) {
        for (auto &arg : args) {
            std::cout << arg;
        }
    }

    return true;
}

} // namespace cmd
} // namespace turnip
