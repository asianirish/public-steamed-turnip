#include "TaskManager.h"

#include "cmd/PrintAction.h"
#include "common/Factory.h"

namespace turnip {
namespace cmd {

TaskManager::TaskManager() {}

void TaskManager::execute(const Value &actionDesc, const InputArgList &inputArgs)
{
    auto data = actionDesc.data();

    std::string *pClassName = std::get_if<std::string>(&data);

    if (pClassName) {
        auto className = *pClassName;
        std::cout << "executing action: " << className << std::endl;
        auto action = common::Factory<Action>::create(className);
        auto actionPtr = ActionPtr(action);
        if (actionPtr) {

            ArgList args;
            auto actionDef = actionPtr->actionDef();
            auto argDefs = actionDef.argDefs();
            auto inputArgIt = inputArgs.begin();

            for (auto &inputArg : inputArgs) { // TODO: (auto &argDef : argDefs)
                // TODO: convert to a corresponding Value type
                // TODO: auto arg = argDef.convert(inputArg);
                args.push_back(inputArg); // TODO: args.push_back(arg);
                ++inputArgIt;
            }

            // Create a new thread to execute the action
            std::thread actionThread(&TaskManager::executeAction, this, actionPtr, args);

            // actionThread.get_id();

            // Detach the thread if you don't need to join it later
            actionThread.detach();
        }
    }

    } // TODO: handle map




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
