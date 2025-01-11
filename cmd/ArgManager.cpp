#include "ArgManager.h"

namespace turnip {
namespace cmd {

ArgManager::ArgManager() {

    {
        auto f = std::bind(&ArgManager::onArgResult, this, std::placeholders::_1);
        taskManager_.setCallback(f);
    }

    {
        auto f = std::bind(&ArgManager::onArgError, this, std::placeholders::_1);
        taskManager_.setErrorCallback(f);
    }
}

bool ArgManager::execArgs(const ArgList &args)
{
    // TODO: implement
    (void)args;
    return false; // returns `true` if at least one task is executed in a separate thread.
}

void ArgManager::onArgResult(const Result &result)
{
    // TODO: implement
    std::cout << "ARG RESULT: " << result.value() << std::endl;
}

void ArgManager::onArgError(const err::Error &error)
{
    // TODO: implement
    std::cout << "ARG ERROR: " << error.description() << std::endl;
}

} // namespace cmd
} // namespace turnip
