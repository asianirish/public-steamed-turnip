#include "SyncAction.h"
#include "cmd/Result.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {

SyncAction::SyncAction() {}

void SyncAction::act(const TaskId &taskId, const ArgList &args)
{
    auto error = err::Error::createTaskError(taskId, "Unkown task error");
    // Call the specific action implementation
    Value value = actImpl(args, error);


    if (!value.isNull()) {
        auto rep = actionDef().resultRepresentation();

        // Notify that actImpl has concluded
        Result result(taskId, value, rep);
        notify(result);
    } else {
        notifyError(error);
    }
}


} // namespace cmd
} // namespace turnip
