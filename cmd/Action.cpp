#include "Action.h"
#include "cmd/Result.h"
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

void Action::act(const TaskId &taskId, const ArgList &args)
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

void Action::notify(const Result &result)
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

ActionPtr Action::fromMap(const VariantMap &mp)
{
    auto className = mp.get(CLASS_NAME_KEY).toString();
    auto lazyAction = LazyAction(className);

    if (mp.contains(DATA_KEY)) {
        auto data = mp.get(DATA_KEY).toMap();
        lazyAction->setData(data);
    }

    return lazyAction.ptr();
}

ActionPtr Action::clone() const
{
    LazyAction cln(registeredClassName());
    cln->setData(data());
    return cln.ptr();
}

void Action::setErrorCallback(const ErrorCallback &newErrorCallback)
{
    errorCallback_ = newErrorCallback;
}

} // namespace cmd
} // namespace turnip
