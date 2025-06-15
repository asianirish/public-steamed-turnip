#include "ActionEvState.h"

namespace turnip {
namespace cmd {
namespace loop {

ActionEvState::ActionEvState(StateManager *manager, TaskId loopTaskId,
                             const ActionPtr &action, const ArgList &args,
                             const ActionPtr &evAction, const ArgList &evArgs) : State(manager, loopTaskId, action, args),
    evAction_(evAction), evArgData_(evArgs)
{
    {
        auto f = std::bind(&ActionEvState::onEvaluationActionResult, this, std::placeholders::_1);
        evTaskManager_.setCallback(f);
    }

    {
        auto f = std::bind(&ActionEvState::onEvaluationActionError, this, std::placeholders::_1);
        evTaskManager_.setErrorCallback(f);
    }
}

int ActionEvState::resultEvArgumentIndex() const
{
    return resultEvArgumentIndex_;
}

void ActionEvState::setResultEvArgumentIndex(int newResultEvArgumentIndex)
{
    resultEvArgumentIndex_ = newResultEvArgumentIndex;
}

void ActionEvState::handleResult(const Value resultValue)
{
    prevResultValue_ = resultValue;
    if (resultValue.isMap()) {
        // TODO: map result values to evArgData_ by ArgDefs of evAction_
    } else if (resultEvArgumentIndex_ != INVALID_RESULT_INDEX){
        evArgData_[resultEvArgumentIndex_] = resultValue;
    }

}

void ActionEvState::evaluate()
{
    evTaskManager_.execute(evAction_, evArgData_);
}

void ActionEvState::modifyArgData(ArgList &newArgData)
{
    if (prevResultValue_.isMap()) {
        // TODO: map result values to newArgData
    } else if (resultArgumentIndex_ != INVALID_RESULT_INDEX) {
        if (!prevResultValue_.isNull()) {
            newArgData[resultArgumentIndex_] = prevResultValue_;
        }
    }


}

void ActionEvState::nextState()
{
    // This implementation doesn't have states
}

Value ActionEvState::accumulated() const
{
    // TODO: implement Acumulator class
    return true;
}

int ActionEvState::resultArgumentIndex() const
{
    return resultArgumentIndex_;
}

void ActionEvState::setResultArgumentIndex(int newResultArgumentIndex)
{
    resultArgumentIndex_ = newResultArgumentIndex;
}

void ActionEvState::onEvaluationActionResult(const Result &result)
{
    onEvaluationResult(result.value().toBool());
}

void ActionEvState::onEvaluationActionError(const err::Error &error)
{
    // TODO: implement
    (void) error;
}

} // namespace loop
} // namespace cmd
} // namespace turnip
