#include "TaskManager.h"
#include "cmd/Action.h"
#include "cmd/Task.h"
#include "cmd/err/ConversionException.h"

namespace turnip {
namespace cmd {

TaskManager::TaskManager() {}

void TaskManager::execute(const ActionPtr &actionPtr, const InputArgList &inputArgs)
{
    auto taskPtr = task(actionPtr, inputArgs);

    if (taskPtr) {
        execute(taskPtr);
    }
}

void TaskManager::onTaskComplete(const Result &result)
{
    auto taskId = result.taskId();

#if __cplusplus >= 202002L
    if (tasks_.contains(taskId)) {
#else
    if (tasks_.find(taskId) != tasks_.end()) {
#endif

        if (result.isTask()) {
            if (handleTaskResult(result)) {
                return;
            }
        }

        // TODO: handle a list of tasks

        // TODO: do not delete the task immediately (when?) and set Completed status (?)
        tasks_.erase(taskId);

        if (callback_) {
            callback_(result);
        }
    }
    // TODO: save the result of pure functions
}

void TaskManager::onError(const err::Error &error)
{
    auto maybeTaskId = error.maybeTaskId();

    if (!maybeTaskId) {
        throw "no taskId in error"; // TODO: exception class
    }

    auto taskId = *maybeTaskId;

#if __cplusplus >= 202002L
    if (tasks_.contains(taskId)) {
#else
    if (tasks_.find(taskId) != tasks_.end()) {
#endif
        // TODO: do not delete the task immediately (when?) and set Failed status (?)
        tasks_.erase(taskId);

        if (errorCallback_) {
            errorCallback_(error);
        }
    }
}

TaskPtr TaskManager::task(const ActionPtr &actionPtr, const InputArgList &inputArgs)
{
    ArgList args;
    auto actionDef = actionPtr->actionDef();
    auto argDefs = actionDef.argDefs();
    auto inputArgIt = inputArgs.begin();

    int index = 0;
    for (auto &argDef : argDefs) {
        Value arg;
        if (inputArgIt != inputArgs.end()) {
            try {
                arg = argDef.convertInput(*inputArgIt);
            } catch (err::ConversionException &e) {
                auto error = err::Error::createArgumentConversionError(e.type(), e.input(), index, argDef.name());
                errorCallback_(error);
                return {};
            }
        } else {
            arg = argDef.defaultValue();

            if (arg.isNull()) {
                auto error = err::Error::createMissingRequiredArgumentError(index, argDef.name());
                errorCallback_(error);
                return {};
            }
        }
        args.push_back(arg);

        if (inputArgIt != inputArgs.end()) {
            ++inputArgIt;
        }
        ++index;
    }

    return TaskPtr(new Task(actionPtr, args));
}

bool TaskManager::handleTaskResult(const Result &result)
{
    auto rep = result.representation();
    if (!rep || rep->metaType().type() != def::MetaType::Task) {
        auto taskId = result.taskId();
        auto task = tasks_.at(taskId);
        auto subTask = result.value().toTaskPtr();

        {
            auto f = std::bind(&TaskManager::onTaskComplete, this, std::placeholders::_1);
            task->setSubTaskCallback(f);
        }

        {
            auto f = std::bind(&TaskManager::onError, this, std::placeholders::_1);
            task->setErrorSubTaskCallback(f);
        }

        task->executeSubTask(subTask);
        return true;
    }

    return false;
}

void TaskManager::execute(const TaskPtr &taskPtr, ExecType execType)
{
    auto taskId = taskPtr->taskId();
    auto actionPtr = taskPtr->actionPtr();
    tasks_.insert({taskId, taskPtr});

    {
        auto f = std::bind(&TaskManager::onTaskComplete, this, std::placeholders::_1);
        actionPtr->setCallback(f);
    }

    {
        auto f = std::bind(&TaskManager::onError, this, std::placeholders::_1);
        actionPtr->setErrorCallback(f);
    }

    if (startCallback_) {
        startCallback_(taskId);
    }

    taskPtr->execute(execType);
}

void TaskManager::setStartCallback(const StartCallback &newStartCallback)
{
    startCallback_ = newStartCallback;
}

void TaskManager::setErrorCallback(const ErrorCallback &newErrorCallback)
{
    errorCallback_ = newErrorCallback;
}

void TaskManager::setCallback(const ResultCallback &newCallback)
{
    callback_ = newCallback;
}

} // namespace cmd
} // namespace turnip
