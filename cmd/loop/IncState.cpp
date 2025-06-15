#include "IncState.h"

namespace turnip {
namespace cmd {
namespace loop {

IncState::IncState(StateManager *manager, TaskId loopTaskId, const ActionPtr &action, const ArgList &args) : SyncEvState(manager, loopTaskId, action, args) {}

int IncState::counter() const
{
    return counter_;
}

void IncState::setCounter(int newCounter)
{
    counter_ = newCounter;
}

int IncState::upTo() const
{
    return upTo_;
}

void IncState::setUpTo(int newUpTo)
{
    upTo_ = newUpTo;
}

bool IncState::evaluateSync() const
{
    return (counter_ < upTo_);
}

void IncState::modifyArgData(ArgList &newArgData)
{
    if (counterArgumentIndex_ != IncState::INVALID_COUNTER_ARGUMENT_INDEX) {
        newArgData[counterArgumentIndex_] = counter_;
    }
}

void IncState::nextState()
{
    initialCounter_ ++;
    counter_++;
}

Value IncState::accumulated() const
{
    return initialCounter_;
}

int IncState::counterArgumentIndex() const
{
    return counterArgumentIndex_;
}

void IncState::setCounterArgumentIndex(int newCounterArgumentIndex)
{
    counterArgumentIndex_ = newCounterArgumentIndex;
}

void IncState::handleResult(const Value resultValue)
{
    (void) resultValue;
}

} // namespace loop
} // namespace cmd
} // namespace turnip
