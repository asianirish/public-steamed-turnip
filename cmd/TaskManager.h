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

    void execute(const LazyAction &action, const InputArgList& inputArgs);

    void setCallback(const ResultCallback &newCallback);

    void setErrorCallback(const ErrorCallback &newErrorCallback);

private:
    // Function to execute the action in a separate thread
    void executeAction(ActionPtr actionPtr, const ArgList& args);

    // Member function to be called upon action completion
    [[deprecated("use onTaskComplete instead")]] void onActionComplete(const Value &result);
    void onTaskComplete(const Value &result, TaskId taskId);

    TaskPtr task(const LazyAction &action, const InputArgList &inputArgs);

    ResultCallback callback_;
    ErrorCallback errorCallback_;

    std::map<TaskId, TaskPtr> tasks_;
};

} // namespace cmd
} // namespace turnip

#endif // TASKMANAGER_H
