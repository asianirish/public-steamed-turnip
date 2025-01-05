#ifndef TASK_H
#define TASK_H

#include "cmd/Result.h"
#include "cmd/Types.h"
#include "cmd/err/Error.h"

#include <functional>

namespace turnip {
namespace cmd {

class TaskManager;

class Task
{
public:
    enum class Status {
        Pending,
        Running,
        Completed,
        Failed
    };

    static const TaskId FIRST_TASK_ID = 1024;

    // Define a type for the callback function
    using Callback = std::function<void(const Result&)>;
    using ErrorCallback = std::function<void(const TaskId&, const err::Error&)>;

    Task();

    Task(ActionPtr actionPtr, const ArgList &argList);

    ActionPtr actionPtr() const;
    void setActionPtr(const ActionPtr &newActionPtr);

    ArgList argList() const;
    void setArgList(const ArgList &newArgList);

    operator bool() const;

    void execute(ExecType execType = ExecType::Auto);

    TaskId taskId() const;

    Status status() const;

    void executeSubTask(const TaskPtr &subTask);

    void setSubTaskCallback(const Callback &newSubTaskCallback);

    void setErrorSubTaskCallback(const ErrorCallback &newErrorSubTaskCallback);

private:
    ActionPtr actionPtr_;
    ArgList argList_;

    TaskId taskId_;
    static TaskId maxTaskId_;

    // Current status of the task
    Status status_;

    std::map<TaskId, TaskPtr> argTasks_;

    std::shared_ptr<TaskManager> subTaskManager_;

    Callback subTaskCallback_; // Member to hold the callback function
    ErrorCallback errorSubTaskCallback_;

    void executeAction();

    void onSubTaskComplete(const Result &result);
    void onSubTaskError(const err::Error &error);
};

} // namespace cmd
} // namespace turnip

#endif // TASK_H
