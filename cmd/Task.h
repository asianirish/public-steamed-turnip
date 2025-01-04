#ifndef TASK_H
#define TASK_H

#include "cmd/Types.h"

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

    Task();

    Task(ActionPtr actionPtr, const ArgList &argList);

    ActionPtr actionPtr() const;
    void setActionPtr(const ActionPtr &newActionPtr);

    ArgList argList() const;
    void setArgList(const ArgList &newArgList);

    operator bool() const;

    void execute();

    TaskId taskId() const;

    Status status() const;

private:
    ActionPtr actionPtr_;
    ArgList argList_;

    TaskId taskId_;
    static TaskId maxTaskId_;

    // Current status of the task
    Status status_;

    std::map<TaskId, TaskPtr> argTasks_;

    void executeAction();
};

} // namespace cmd
} // namespace turnip

#endif // TASK_H
