#include "AsyncAction.h"

namespace turnip {
namespace cmd {

AsyncAction::AsyncAction() {}

void AsyncAction::specificAct(const TaskId &taskId, const ArgList &args)
{
    emitRequest(taskId, args);
}

void AsyncAction::onComplete(const Value &reslutValue, const TaskId &taskId)
{
    if (!reslutValue.isNull()) {
        auto rep = actionDef().resultRepresentation();

        // Notify that the action has concluded
        Result result(taskId, reslutValue, rep);
        notify(result);
#ifdef DEBUG_ASYNC_ACTIONS
        std::cout << "emitting result value " << reslutValue.toString() << " " << taskId << std::endl;
#endif
        emitComplete(reslutValue, taskId);
    } else {
        auto error = err::Error::createTaskError(taskId, "Unkown task error");

#ifdef DEBUG_ASYNC_ACTIONS
        std::cout << "emitting error" << std::endl;
#endif
        notifyError(error);
        // TODO: emitError(error);
    }
}

void AsyncAction::onError(const err::Error &error)
{
    notifyError(error);
}

void AsyncAction::onSubTaskComplete(const Value &reslutValue, const TaskId &taskId)
{
    if (!reslutValue.isNull()) {

#ifdef DEBUG_ASYNC_ACTIONS
        std::cout << "emitting subtask result value " << reslutValue.toString() << " " << taskId << std::endl;
#endif
        emitComplete(reslutValue, taskId);
    } else {
#ifdef DEBUG_ASYNC_ACTIONS
        std::cout << "emitting subtask error" << std::endl;
#endif
        // TODO: emitError(error);
    }
}

} // namespace cmd
} // namespace turnip
