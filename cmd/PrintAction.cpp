#include "PrintAction.h"

#include <iostream>
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

    actionDef.setDescription("Outputs the specified string");

    return actionDef;
}

Value PrintAction::actImpl(const ArgList &args, err::Error &error)
{
    (void)error;

    sleep(20);
    // using namespace std::chrono_literals;
    // std::this_thread::sleep_for(20s);

    for (int i = 0; i < 100000; ++i) {
        for (auto &arg : args) {
            mutex_.lock();
            for (int j = 0; j < 20; ++j) {
                std::cout << arg;
            }
            std::cout << std::endl;
            mutex_.unlock();
        }
    }

    return true;
}

} // namespace cmd
} // namespace turnip
