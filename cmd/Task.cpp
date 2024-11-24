#include "Task.h"

namespace turnip {
namespace cmd {

Task::Task() : Task({}, {}) {}

Task::Task(ActionPtr actionPtr, const ArgList &argList)
    : actionPtr_(actionPtr), argList_(argList)
{

}

ActionPtr Task::actionPtr() const
{
    return actionPtr_;
}

void Task::setActionPtr(const ActionPtr &newActionPtr)
{
    actionPtr_ = newActionPtr;
}

ArgList Task::argList() const
{
    return argList_;
}

void Task::setArgList(const ArgList &newArgList)
{
    argList_ = newArgList;
}

Task::operator bool() const
{
    return static_cast<bool>(actionPtr_);
}

} // namespace cmd
} // namespace turnip
