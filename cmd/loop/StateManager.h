#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {
namespace loop {

class StateManager
{
public:
    StateManager();

    void addState(const StatePtr &state);

    void deleteState(StateId stateId);

private:
    std::map<StateId, StatePtr> states_;
};

} // namespace loop
} // namespace cmd
} // namespace turnip

#endif // STATEMANAGER_H
