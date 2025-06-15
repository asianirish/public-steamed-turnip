#include "StateManager.h"
#include "State.h"

namespace turnip {
namespace cmd {
namespace loop {

StateManager::StateManager() {}

void StateManager::addState(const StatePtr &state)
{
    states_.insert({state->stateId(), state});
}

void StateManager::deleteState(StateId stateId)
{
    // Attempt to erase the key from the map; no effect if the key does not exist
    states_.erase(stateId);
}

} // namespace loop
} // namespace cmd
} // namespace turnip
