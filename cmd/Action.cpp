#include "Action.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {

const std::string Action::CLASS_NAME_KEY {"className"};
const std::string Action::DATA_KEY {"data"};

Action::Action() {}

void Action::setCallback(Callback callback)
{
    callback_ = callback;
}

void Action::act(const ArgList &args)
{
    auto error = err::Error::createCustomError("Unkown error");
    // Call the specific action implementation
    Value result = actImpl(args, error);

    if (!result.isNull()) {
        // Notify that actImpl has concluded
        notify(result);
    } else {
        notifyError(error);
    }
}

void Action::notify(const Value &result)
{
    if (callback_) {
        callback_(result);
    }
}

void Action::notifyError(const err::Error &error)
{
    if (errorCallback_) {
        errorCallback_(error);
    }
}

std::string Action::registeredClassName() const
{
    if (registeredClassName_) {
        return *registeredClassName_;
    }

    return {};
}

void Action::setRegisteredClassName(const std::string *newRegisteredClassName)
{
    registeredClassName_ = newRegisteredClassName;
}

VariantMap Action::toMap() const
{
    VariantMap mp;
    if (registeredClassName_) {
        mp.set(CLASS_NAME_KEY, *registeredClassName_);
    }

    if (!data().empty()) {
        mp.set(DATA_KEY, data());
    }

    return mp;
}

void Action::setErrorCallback(const ErrorCallback &newErrorCallback)
{
    errorCallback_ = newErrorCallback;
}

} // namespace cmd
} // namespace turnip
