#ifndef TASK_H
#define TASK_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {

class Task
{
public:
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

private:
    ActionPtr actionPtr_;
    ArgList argList_;

    TaskId taskId_;
    static TaskId maxTaskId_;

    void executeAction();

    // 'Slot' to be called on action completion
    void onActionComplete(const Value &result);
};

} // namespace cmd
} // namespace turnip

#endif // TASK_H
