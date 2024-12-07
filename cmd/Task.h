#ifndef TASK_H
#define TASK_H

#include "cmd/Types.h"
#include "cmd/err/Error.h"

#include <functional>

namespace turnip {
namespace cmd {

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
    using ResultCallback = std::function<void(const Value&, TaskId)>;
    using ErrorCallback = std::function<void(const err::Error&, TaskId)>;

    Task();

    Task(ActionPtr actionPtr, const ArgList &argList);

    ActionPtr actionPtr() const;
    void setActionPtr(const ActionPtr &newActionPtr);

    ArgList argList() const;
    void setArgList(const ArgList &newArgList);

    operator bool() const;

    void execute();

    TaskId taskId() const;

    ResultCallback resultCallback() const;
    void setResultCallback(const ResultCallback &newResultCallback);

    void setErrorCallback(const ErrorCallback &newErrorCallback);

    Status status() const;

private:
    ActionPtr actionPtr_;
    ArgList argList_;

    TaskId taskId_;
    static TaskId maxTaskId_;

    ResultCallback resultCallback_;
    ErrorCallback errorCallback_;

    // Current status of the task
    Status status_;

    void executeAction();

    // 'Slot' to be called on action completion
    void onActionComplete(const Value &result);
    void onError(const err::Error &error);
};

} // namespace cmd
} // namespace turnip

#endif // TASK_H
