#include "AsyncAction.h"

namespace turnip {
namespace cmd {

AsyncAction::AsyncAction() {}

void AsyncAction::act(const TaskId &taskId, const ArgList &args)
{
    auto error = err::Error::createTaskError(taskId, "Unkown task error");
    emitRequest(taskId, args, error);
}

void AsyncAction::onComplete(const Value &reslutValue, const TaskId &taskId)
{
    if (!reslutValue.isNull()) {
        auto rep = actionDef().resultRepresentation();

        // Notify that the action has concluded
        Result result(taskId, reslutValue, rep);
        notify(result);
    } else {
        auto error = err::Error::createTaskError(taskId, "Unkown task error");
        notifyError(error);
    }
}

void AsyncAction::onError(const err::Error &error)
{
    notifyError(error);
}

} // namespace cmd
} // namespace turnip
