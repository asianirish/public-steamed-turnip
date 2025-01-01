#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "cmd/Result.h"
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
    using StartCallback = std::function<void(const TaskId&)>;

    void execute(const LazyAction &action, const InputArgList& inputArgs);

    void setCallback(const ResultCallback &newCallback);

    void setErrorCallback(const ErrorCallback &newErrorCallback);

    void setStartCallback(const StartCallback &newStartCallback);

private:
    // Member function to be called upon task completion
    void onTaskComplete(const Result &result);
    void onError(const TaskId &taskId, const err::Error &error);

    TaskPtr task(const LazyAction &action, const InputArgList &inputArgs);

    ResultCallback callback_;
    ErrorCallback errorCallback_;
    StartCallback startCallback_;

    std::map<TaskId, TaskPtr> tasks_;
};

} // namespace cmd
} // namespace turnip

#endif // TASKMANAGER_H
