#include "TaskManager.h"
#include "cmd/SyncAction.h"
#include "cmd/Task.h"
#include "cmd/err/ConversionException.h"

#include "cmd/AsyncAction.h"

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

TaskPtr TaskManager::execute(const ActionPtr &actionPtr, const ArgList &args)
{
    auto taskPtr = task(actionPtr, args);

    if (taskPtr) {
        execute(taskPtr);
    }

    return taskPtr;
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
#ifdef DEBUG_ACTION_TASKS
            std::cout << "THE RESULT IS A TASK " << taskId << std::endl;
#endif

            if (handleTaskResult(result)) {
                return;
            }
        }

        // TODO: handle a list of tasks
        auto tsk = tasks_.at(taskId);

        // TODO: do not delete the task immediately (when?) and set Completed status (?)
        tasks_.erase(taskId); // here

        auto asyncAction = std::dynamic_pointer_cast<AsyncAction>(tsk->actionPtr());

        if (asyncAction) {
#ifdef DEBUG_ASYNC_ACTIONS
            std::cout << std::endl << "async action ON_SUB_TASK_COMPLETE" << std::endl;
#endif
            asyncAction->onSubTaskComplete(result.value(), result.taskId());

#ifdef DEBUG_ASYNC_ACTIONS
            std::cout << "async action SUB_TASK_COMPLETE" << std::endl;
#endif
        }

        for (const auto &callback : callbacks_) {
            callback(result);
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

        for (const auto &errorCallback : errorCallbacks_) {
            errorCallback(error);
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
    for (const auto &argDef : argDefs) {
        Value arg;
        if (inputArgIt != inputArgs.end()) {
            try {
                arg = argDef.convertInput(*inputArgIt);
            } catch (err::ConversionException &e) {
                auto error = err::Error::createArgumentConversionError(e.type(), e.input(), index, argDef.name());
                for (const auto &errorCallback : errorCallbacks_) {
                    errorCallback(error);
                }
                return {};
            }
        } else {
            arg = argDef.defaultValue();

            if (arg.isNull()) {
                auto error = err::Error::createMissingRequiredArgumentError(index, argDef.name());
                for (const auto &errorCallback : errorCallbacks_) {
                    errorCallback(error);
                }
                return {};
            }
        }
        args.push_back(arg);

        if (inputArgIt != inputArgs.end()) {
            ++inputArgIt;
        }
        ++index;
    }

    return task(actionPtr, args);
}

TaskPtr TaskManager::task(const ActionPtr &actionPtr, const ArgList &args)
{
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
            // TODO: different function for subtask? (TaskManager::onSubTaskComplete?)
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

    {
        auto f = std::bind(&TaskManager::onError, this, std::placeholders::_1);
        taskPtr->setArgErrorCallback(f);
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
    errorCallbacks_.push_back(newErrorCallback);
}

void TaskManager::setCallback(const ResultCallback &newCallback)
{
    callbacks_.push_back(newCallback);
}

} // namespace cmd
} // namespace turnip
