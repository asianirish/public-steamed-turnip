#include "Action.h"

namespace turnip {
namespace cmd {

const std::string Action::CLASS_NAME_KEY {"className"};
const std::string Action::DATA_KEY {"data"};

void Action::setCallback(Callback callback)
{
    callback_ = callback;
}

void Action::setErrorCallback(const ErrorCallback &newErrorCallback)
{
    errorCallback_ = newErrorCallback;
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
    auto actionPtr = ActionPtr(common::Factory<Action>::create(className));

    if (mp.contains(DATA_KEY)) {
        auto data = mp.get(DATA_KEY).toMap();
        actionPtr->setData(data);
    }

    return actionPtr;
}

ActionPtr Action::clone() const
{
    auto cln = ActionPtr(common::Factory<Action>::create(registeredClassName()));
    cln->setData(data());
    return cln;
}

} // namespace cmd
} // namespace turnip
