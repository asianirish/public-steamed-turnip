#include "AsyncPrintAction.h"
#include "cmd/PrintAction.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

AsyncPrintAction::AsyncPrintAction() {
    _printAction = mkActionPtr(PrintAction);
}

def::ActionDef AsyncPrintAction::actionDef() const
{
    return _printAction->actionDef();
}

void AsyncPrintAction::emitRequest(const TaskId &taskId, const ArgList &args)
{
    TaskPtr taskPtr(new Task());
    taskPtr->setActionPtr(_printAction);
    taskPtr->setArgList(args);

    auto rep = actionDef().resultRepresentation();
    Result result(taskId, taskPtr, rep);
    notify(result);
}

void AsyncPrintAction::emitComplete(const Value &reslutValue, const TaskId &taskId)
{
    std::cout << std::endl << "ASYNC PRINT RESULT IS: " << reslutValue << " " << taskId << std::endl;
}

} // namespace cmd
} // namespace turnip
