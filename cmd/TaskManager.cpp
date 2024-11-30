#include "TaskManager.h"
#include "cmd/Action.h"
#include "cmd/err/ConversionException.h"

#include "common/Factory.h"

#include <iostream>

namespace turnip {
namespace cmd {

TaskManager::TaskManager() {}

void TaskManager::execute(const Value &actionDesc, const InputArgList &inputArgs)
{
    auto data = actionDesc.data();

    std::string *pClassName = std::get_if<std::string>(&data);

    if (pClassName) {
        auto className = *pClassName;

        auto tsk = task(className, inputArgs);

        if (tsk) {
            // TEST: alternative for std::thread
            // auto a = std::async(&TaskManager::executeAction, this, actionPtr, args);
            // auto b = a.share();
            // static std::list<decltype(b)> lst;
            // lst.push_back(b);

            // Create a new thread to execute the action
            std::thread actionThread(&TaskManager::executeAction, this, tsk.actionPtr(), tsk.argList());

            // actionThread.get_id();

            // Detach the thread if you don't need to join it later
            actionThread.detach();
        }
    }
    // TODO: handle map

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

Task TaskManager::task(const std::string &className, const InputArgList &inputArgs)
{
    std::cout << "executing action: " << className << std::endl;
    auto action = common::Factory<Action>::create(className);
    auto actionPtr = ActionPtr(action);
    if (actionPtr) {
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

        return Task(actionPtr, args);
    }

    return {};
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
