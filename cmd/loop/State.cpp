#include "State.h"
#include "cmd/TaskIdIncGenerator.h"
#include "cmd/Action.h"

namespace turnip {
namespace cmd {
namespace loop {

std::shared_ptr<TaskIdGenerator> State::stateIdGen_;

State::State(StateManager *manager, TaskId loopTaskId, const ActionPtr &action, const ArgList &args) : manager_(manager),
    loopTaskId_(loopTaskId),
    action_(action),
    argData_(args) // TODO: convert to VariantMap
{
    if (!stateIdGen_) {
        stateIdGen_ = std::make_shared<TaskIdIncGenerator>();
        stateIdGen_->init();
    }

    stateId_ = stateIdGen_->next();

    {
        auto f = std::bind(&State::onResult, this, std::placeholders::_1);
        taskManager_.setCallback(f);
    }

    {
        auto f = std::bind(&State::onError, this, std::placeholders::_1);
        taskManager_.setErrorCallback(f);
    }
}

void State::start()
{
    manager_->addState(shared_from_this());

    evaluate(); // evaluate for the first time
}

void State::execute(const ActionPtr &action, ArgList args)
{
    taskManager_.execute(action, args);
}

void State::setResultCallback(const ResultCallback &newResultCallback)
{
    resultCallback_ = newResultCallback;
}

TaskId State::stateId() const
{
    return stateId_;
}

void State::onResult(const Result &result)
{
    // Alters the state to influence the evaluation process.
    handleResult(result.value());

    evaluate();
}

void State::onError(const err::Error &error)
{
    (void) error;
    // TODO: implement
}

void State::step()
{
    modifyArgData(argData_);
    // Invoke `nextState` before executing the action, as `execute` may trigger a new callback to `onResult`
    nextState();
    execute(action_, argData_);
}

void State::onEvaluationResult(bool success)
{
    if (success) {
        step();
    } else {
        // notify a loop action
        if (resultCallback_) {
            Result newResult;
            newResult.setValue(accumulated());
            newResult.setTaskId(loopTaskId_);
            resultCallback_(newResult);
        }

        manager_->deleteState(stateId_);
    }
}

} // namespace loop
} // namespace cmd
} // namespace turnip
