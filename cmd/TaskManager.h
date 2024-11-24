#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "cmd/Task.h"
#include "cmd/Types.h"
#include "cmd/err/Error.h"

#include <functional>

namespace turnip {
namespace cmd {

class TaskManager
{
public:
    TaskManager();

    using ResultCallback = std::function<void(const Value&)>;
    using ErrorCallback = std::function<void(const err::Error&)>;

    void execute(const Value &actionDesc, const InputArgList& inputArgs);

    void setCallback(const ResultCallback &newCallback);

    void setErrorCallback(const ErrorCallback &newErrorCallback);

private:
    // Function to execute the action in a separate thread
    void executeAction(ActionPtr actionPtr, const ArgList& args);

    // Member function to be called upon action completion
    void onActionComplete(const Value &result);

    Task task(const std::string &className, const InputArgList &inputArgs);

    ResultCallback callback_;
    ErrorCallback errorCallback_;
};

} // namespace cmd
} // namespace turnip

#endif // TASKMANAGER_H
