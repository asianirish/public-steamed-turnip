#include "TaskManager.h"
#include "cmd/Action.h"
#include "cmd/err/ConversionException.h"

#include <iostream>

namespace turnip {
namespace cmd {

TaskManager::TaskManager() {}

void TaskManager::execute(const LazyAction &action, const InputArgList &inputArgs)
{
    auto tsk = task(action, inputArgs);

    if (tsk) {
        auto taskId = tsk->taskId();
        tasks_.insert({taskId, tsk});

        tsk->execute();
    }
}

void TaskManager::executeAction(ActionPtr action, const ArgList &args)
{
    // Set a callback using TaskManager's member function
    action->setCallback(std::bind(&TaskManager::onActionComplete, this, std::placeholders::_1));

    // Call the act method, which will execute actSpecific
    action->act(args);
}

void TaskManager::onActionComplete(const Value &result)
{
    // TODO: save the result of pure functions

    if (callback_) {
        callback_(result);
    }
}

TaskPtr TaskManager::task(const LazyAction &action, const InputArgList &inputArgs)
{
    auto actionPtr = action.ptr();
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
        std::cout << "DEBUG ARG:" << arg << std::endl;
        args.push_back(arg);

        if (inputArgIt != inputArgs.end()) {
            ++inputArgIt;
        }
        ++index;
    }

    return TaskPtr(new Task(actionPtr, args));
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
