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

private:
    ActionPtr actionPtr_;
    ArgList argList_;
};

} // namespace cmd
} // namespace turnip

#endif // TASK_H
