#include "Task.h"
#include "cmd/Action.h"
#include "cmd/Value.h"
#include <functional>
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
}

TaskId Task::taskId() const
{
    return taskId_;
}

Task::ResultCallback Task::resultCallback() const
{
    return resultCallback_;
}

void Task::setResultCallback(const ResultCallback &newResultCallback)
{
    resultCallback_ = newResultCallback;
}

void Task::setErrorCallback(const ErrorCallback &newErrorCallback)
{
    errorCallback_ = newErrorCallback;
}

Status Task::status() const
{
    return status_;
}

void Task::executeAction()
{
    // Set a callback using Task's member function
    actionPtr_->setCallback(std::bind(&Task::onActionComplete, this, std::placeholders::_1));
    actionPtr_->setErrorCallback(std::bind(&Task::onError, this, std::placeholders::_1));

    // Call the act method, which will execute actSpecific

    actionPtr_->act(argList_);
}

void Task::onActionComplete(const Value &result)
{
    std::cout << "TASK RESULT IS: " << result << std::endl;
    status_ = Status::Completed;

    if (resultCallback_) {
        resultCallback_(result, taskId_);
    }
}

void Task::onError(const err::Error &error)
{
    status_ = Status::Failed;

    if (errorCallback_) {
        errorCallback_(error, taskId_);
    }
}

} // namespace cmd
} // namespace turnip
