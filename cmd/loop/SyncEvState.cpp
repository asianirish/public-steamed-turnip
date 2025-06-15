#include "SyncEvState.h"

namespace turnip {
namespace cmd {
namespace loop {

SyncEvState::SyncEvState(StateManager *manager, TaskId loopTaskId, const ActionPtr &action, const ArgList &args) :
    State(manager, loopTaskId, action, args)
{

}

void SyncEvState::evaluate()
{
    onEvaluationResult(evaluateSync());
}

} // namespace loop
} // namespace cmd
} // namespace turnip
