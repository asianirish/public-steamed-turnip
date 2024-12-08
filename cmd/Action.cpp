#include "Action.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {

Action::Action() {}

void Action::setCallback(Callback callback)
{
    callback_ = callback;
}

void Action::act(const ArgList &args)
{
    // Lock resources if needed
    std::lock_guard<std::mutex> lock(mutex_);

    auto error = err::Error::createCustomError("Unkown error");
    // Call the specific action implementation
    Value result = actImpl(args, error);

    if (!result.isNull()) {
    // Notify that actImpl has concluded
    notify(result);
    } else {
        // TODO: notify error
    }
}

void Action::notify(const Value &result)
{
    if (callback_) {
        callback_(result);
    }
}

} // namespace cmd
} // namespace turnip
