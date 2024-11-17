#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {

class TaskManager
{
public:
    TaskManager();

    void execute(const Value &actionDesc, const InputArgList& inputArgs);

private:
    // Function to execute the action in a separate thread
    void executeAction(ActionPtr actionPtr, const ArgList& args);

    // Member function to be called upon action completion
    void onActionComplete(const Value &result);
};

} // namespace cmd
} // namespace turnip

#endif // TASKMANAGER_H
