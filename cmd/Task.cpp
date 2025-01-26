#include "Task.h"
#include "cmd/Action.h"
#include "cmd/TaskManager.h"
#include "cmd/ArgInfo.h"

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

    {
        auto f = std::bind(&Task::onArgResults, this, std::placeholders::_1);
        argManager_.setArgResultsCallback(f);
    }

    // TODO: connect the error callback
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

    auto argInfos = subTask->argInfos();

    int index = 0;
    for (auto &argInfo : argInfos) {
        if (argInfo.argDef().defaultValue().isNull()) {
            if (argInfo.value().isNull()) {
                auto error = err::Error::createTaskError(subTask->taskId(),
                    std::string("Missing subtask ") + std::to_string(subTask->taskId()) + " argument [" + std::to_string(index) + "] " +
                    (!argInfo.argDef().name().empty() ? ("('" + argInfo.argDef().name() + "')") : "") );
                onSubTaskError(error);
                return;
            }
        }

        ++index;
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

VariantMap Task::toMap() const
{
    VariantMap mp;

    mp.set("action", actionPtr_);

    VariantList lst;
    for (auto arg : argList_) {
        lst.push_back(arg);
    }
    mp.set("args", lst);

    mp.set("taskId", static_cast<int64_t>(taskId_));

    return mp;
}

Task::Status Task::status() const
{
    return status_;
}

void Task::executeAction()
{
    if (argManager_.execArgs(argInfos())) {
        return;
    }

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
            subResult.setRepresentation(rep); // TODO: actionPtr->repClass()
        }

        subResult.setTaskId(taskId());
        subTaskCallback_(subResult);
    }

}

void Task::onSubTaskError(const err::Error &error)
{
    if (errorSubTaskCallback_) {
        auto errorCopy = error;
        if (errorCopy.maybeSetTaskId(taskId_)) {
            errorSubTaskCallback_(errorCopy);
        } else {
            errorSubTaskCallback_(error);
        }
    }
}

void Task::onArgResults(const ArgResults &argResults)
{
    for (auto pr : argResults) {
        argList_[pr.first] = pr.second;
    }

    executeAction();
}

ArgInfoList Task::argInfos() const
{
    ArgInfoList lst;

    auto argIt = argList_.begin();
    auto actionDef = actionPtr_->actionDef();
    auto argDefs = actionDef.argDefs();

    for (auto &argDef : argDefs) {
        if (argIt  != argList_.end()) {
            lst.push_back(ArgInfo(*argIt, argDef));
            ++argIt;
        } else {
            lst.push_back(ArgInfo(argDef.defaultValue(),argDef));
        }
    }

    return lst;
}

} // namespace cmd
} // namespace turnip
