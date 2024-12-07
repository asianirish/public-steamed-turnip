#ifndef TASK_H
#define TASK_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {

class Task
{
public:
    Task();

    Task(ActionPtr actionPtr, const ArgList &argList);

    ActionPtr actionPtr() const;
    void setActionPtr(const ActionPtr &newActionPtr);

    ArgList argList() const;
    void setArgList(const ArgList &newArgList);

    operator bool() const;

    void execute();

private:
    ActionPtr actionPtr_;
    ArgList argList_;

    void executeAction();

    // 'Slot' to be called on action completion
    void onActionComplete(const Value &result);
};

} // namespace cmd
} // namespace turnip

#endif // TASK_H
