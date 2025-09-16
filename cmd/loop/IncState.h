#ifndef INCSTATE_H
#define INCSTATE_H

#include "SyncEvState.h"

namespace turnip {
namespace cmd {
namespace loop {

class IncState : public SyncEvState
{
public:
    static const int INVALID_COUNTER_ARGUMENT_INDEX = -1;

    IncState(StateManager *manager, TaskId loopTaskId, const ActionPtr &action, const ArgList &args);

    int counter() const;
    void setCounter(int newCounter);

    int upTo() const;
    void setUpTo(int newUpTo);

    int counterArgumentIndex() const;
    void setCounterArgumentIndex(int newCounterArgumentIndex);

    bool isInclusive() const;
    void setIsInclusive(bool newIsInclusive);

protected:
    void handleResult(const Value resultValue) override; // do nothing in this implementation
    bool evaluateSync() const override;
    void modifyArgData(ArgList &newArgData) override;
    void nextState() override;

    Value accumulated() const override;

    int counter_ {0};
    int upTo_ {0};
    int initialCounter_ {0};

    int counterArgumentIndex_ {INVALID_COUNTER_ARGUMENT_INDEX};

    bool isInclusive_ {false};
};

} // namespace loop
} // namespace cmd
} // namespace turnip

#endif // INCSTATE_H
