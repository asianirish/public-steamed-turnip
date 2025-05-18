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

} // namespace cmd
} // namespace turnip
