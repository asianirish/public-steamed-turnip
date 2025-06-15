#ifndef SYNCEVSTATE_H
#define SYNCEVSTATE_H

#include "State.h"

namespace turnip {
namespace cmd {
namespace loop {

class SyncEvState : public State
{
public:
    SyncEvState(StateManager *manager, TaskId loopTaskId, const ActionPtr &action, const ArgList &args);

protected:
    void evaluate() final;

    virtual bool evaluateSync() const = 0;
};

} // namespace loop
} // namespace cmd
} // namespace turnip

#endif // SYNCEVSTATE_H
