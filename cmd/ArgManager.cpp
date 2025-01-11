#include "ArgManager.h"
#include "cmd/ArgInfo.h"
#include "cmd/Task.h"

#include <list>

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

bool ArgManager::execArgs(const ArgInfoList &argInfos)
{
    size_t i = 0;
    std::list<TaskPtr> tasks;

    for (auto &argInfo : argInfos) {
        auto argDef = argInfo.argDef();
        Value value = argInfo;
        if (argDef.mustBeCalculated() && value.isTask()) {
            auto taskPtr = value.toTaskPtr();
            auto taskId = taskPtr->taskId();
            taskToArgNum_.insert({taskId, i});
            tasks.push_back(taskPtr);
        }
        ++i;
    }

    if (tasks.size() == 0) {
        return false;
    }

    if (tasks.size() == 1) {
        auto task = tasks.front();
        taskManager_.execute(task, ExecType::Direct);
        return false;
    }

    for (auto task : tasks) {
        taskManager_.execute(task);
    }

    return true;
}

void ArgManager::onArgResult(const Result &result)
{
    auto argTaskId = result.taskId();
    auto argNum = taskToArgNum_.at(argTaskId);
    calculatedArgs_.insert({argNum, result.value()});

    if (calculatedArgs_.size() == taskToArgNum_.size()) {

        if (argResultsCallback_) {
            argResultsCallback_(calculatedArgs_);
        }

    }
}

void ArgManager::onArgError(const err::Error &error)
{
    // TODO: implement
    std::cout << "ARG ERROR: " << error.description() << std::endl;
}

void ArgManager::setArgResultsCallback(const ArgResultsCallback &newArgResultsCallback)
{
    argResultsCallback_ = newArgResultsCallback;
}

} // namespace cmd
} // namespace turnip
