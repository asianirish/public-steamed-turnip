#include "Task.h"
#include "cmd/Action.h"

#include <thread>

namespace turnip {
namespace cmd {

TaskId Task::maxTaskId_ = Task::FIRST_TASK_ID;

Task::Task() : Task({}, {}) {}

Task::Task(ActionPtr actionPtr, const ArgList &argList)
    : actionPtr_(actionPtr), argList_(argList),
    taskId_(maxTaskId_),
    status_(Status::Pending)
{
    ++maxTaskId_;
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

void Task::execute()
{
    status_ = Status::Running;

    if (actionPtr_->isAsync()) {
        // TEST: alternative for std::thread
        // auto a = std::async(&TaskManager::executeAction, this, actionPtr, args);
        // auto b = a.share();
        // static std::list<decltype(b)> lst;
        // lst.push_back(b);

        // Create a new thread to execute the action
        std::thread actionThread(&Task::executeAction, this);

        // actionThread.get_id();

        // Detach the thread if you don't need to join it later
        actionThread.detach();
    } else {
        executeAction();
    }
}

TaskId Task::taskId() const
{
    return taskId_;
}

Task::Status Task::status() const
{
    return status_;
}

void Task::executeAction()
{
    // Call the act method, which will execute actSpecific
    actionPtr_->act(taskId_, argList_);
}

} // namespace cmd
} // namespace turnip
