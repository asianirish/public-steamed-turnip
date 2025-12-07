#include "Action.h"

#include "def/Constraint.h"

namespace turnip {
namespace cmd {

using namespace def;

const std::string Action::CLASS_NAME_KEY {"className"};
const std::string Action::DATA_KEY {"data"};

void Action::act(const TaskId &taskId, const ArgList &args)
{
    bool ok = false;
    auto handledArgs = handleArgs(args, &ok);

    if (ok) {
        specificAct(taskId, handledArgs);
    }
}

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

ArgList Action::handleArgs(const ArgList &args, bool *ok)
{
    ArgList newArgs;
    // The action's argument definitions, assumed accessible
    const auto &defs = this->actionDef().argDefs();

    // Result flag
    bool result = true;

    size_t i = 0;
    // Ensure we process each expected argument position
    for (const auto &def : defs) {

        Value actual;
        if (i < args.size()) {
            actual = args[i];
        } else {
            // If no value provided, use the default value from the definition
            if (!def.defaultValue().isNull()) {
                actual = def.defaultValue();
            } else {
                result = false;
                return {};
            }
        }

        // Type check
        auto inputType = def.type().inputMetaType().type();
        if (!actual.isTask() && !actual.canConvert(inputType)) { // a task can be calculated
            result = false;
        }

        // Constraint check (if any)
        auto constraint = def.constraint();
        if (constraint && !constraint->isSatisfied(actual)) {
            result = false;
            return {};
        }

        newArgs.push_back(actual);
        ++i;
    }

    if (ok) {
        *ok = result;
    }

    return newArgs;
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
