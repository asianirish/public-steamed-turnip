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

    using ResultCallback = std::function<void(const Result&)>;
    using ErrorCallback = std::function<void(const err::Error&)>;
    using StartCallback = std::function<void(const TaskId&)>;

    void execute(const ActionPtr &actionPtr, const InputArgList& inputArgs);
    TaskPtr execute(const ActionPtr &actionPtr, const ArgList& args);

    void setCallback(const ResultCallback &newCallback);

    void setErrorCallback(const ErrorCallback &newErrorCallback);

    void setStartCallback(const StartCallback &newStartCallback);

    // make public to call in Task
    void execute(const TaskPtr &taskPtr, ExecType execType = ExecType::Auto);

private:
    // Member function to be called upon task completion
    void onTaskComplete(const Result &result);
    void onError(const err::Error &error);

    TaskPtr task(const ActionPtr &actionPtr, const InputArgList &inputArgs);
    TaskPtr task(const ActionPtr &actionPtr, const ArgList &args);

    bool handleTaskResult(const Result &result);

    std::vector<ResultCallback> callbacks_;
    std::vector<ErrorCallback> errorCallbacks_;
    StartCallback startCallback_;

    std::map<TaskId, TaskPtr> tasks_;
};

} // namespace cmd
} // namespace turnip

#endif // TASKMANAGER_H
