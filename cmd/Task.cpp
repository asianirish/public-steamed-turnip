#include "Task.h"
#include "cmd/Action.h"
#include "cmd/TaskManager.h"

#include <thread>

namespace turnip {
namespace cmd {

std::shared_ptr<TaskIdGenerator> Task::taskIdGen_;

Task::Task() : Task({}, {}) {}

Task::Task(ActionPtr actionPtr, const ArgList &argList)
    : actionPtr_(actionPtr), argList_(argList),
    status_(Status::Pending)
{
    if (taskIdGen_) {
        taskId_ = taskIdGen_->next();
    }
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

void Task::execute(ExecType execType)
{
    status_ = Status::Running;

    if (execType == ExecType::Direct) {
        executeAction();
        return;
    }

    if (actionPtr_->isAsync() || execType == ExecType::Thread) {

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

void Task::executeSubTask(const TaskPtr &subTask)
{
    subTaskManager_ = std::make_shared<TaskManager>();

    {
        auto f = std::bind(&Task::onSubTaskComplete, this, std::placeholders::_1);
        subTaskManager_->setCallback(f);
    }

    {
        auto f = std::bind(&Task::onSubTaskError, this, std::placeholders::_1);
        subTaskManager_->setErrorCallback(f);
    }

    subTaskManager_->execute(subTask, ExecType::Direct);
}

void Task::setSubTaskCallback(const Callback &newSubTaskCallback)
{
    subTaskCallback_ = newSubTaskCallback;
}

void Task::setErrorSubTaskCallback(const ErrorCallback &newErrorSubTaskCallback)
{
    errorSubTaskCallback_ = newErrorSubTaskCallback;
}

void Task::setTaskIdGen(const std::shared_ptr<TaskIdGenerator> &newTaskIdGen)
{
    taskIdGen_ = newTaskIdGen;
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

void Task::onSubTaskComplete(const Result &result)
{
    if (subTaskCallback_) {
        Result subResult;
        subResult.setValue(result.value());

        auto rep = actionPtr()->actionDef().resultRepresentation();
        if (rep) {
            subResult.setRepresentation(rep->classKey()); // TODO: actionPtr->repClass()
        }

        subResult.setTaskId(taskId());
        subTaskCallback_(subResult);
    }

}

void Task::onSubTaskError(const err::Error &error)
{
    // TODO: implement
}

} // namespace cmd
} // namespace turnip
