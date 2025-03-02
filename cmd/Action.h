#ifndef ACTION_H
#define ACTION_H

#include "cmd/Result.h"
#include "cmd/Types.h"
#include "def/ActionDef.h"
#include "err/Error.h"

#include <functional>

namespace turnip {
namespace cmd {

class Action
{
public:
    static const std::string CLASS_NAME_KEY;
    static const std::string DATA_KEY;

    Action();
    virtual ~Action() = default;

    // Define a type for the callback function
    using Callback = std::function<void(const Result&)>;
    using ErrorCallback = std::function<void(const err::Error&)>;

    void setCallback(Callback callback);

    void act(const TaskId &taskId, const ArgList &args);

    virtual def::ActionDef actionDef() const = 0;

    void setErrorCallback(const ErrorCallback &newErrorCallback);

    virtual bool startInThread() const {
        return true;
    }

    // should not be used directly
    static std::string checkClassName(const std::string &className) {
        return className;
    }

    std::string registeredClassName() const;
    void setRegisteredClassName(const std::string *newRegisteredClassName);

    VariantMap toMap() const;

    static ActionPtr fromMap(const VariantMap &mp);

    ActionPtr clone() const;

private:
    virtual Value actImpl(const ArgList &args, err::Error &error) = 0;

    // Function to notify via callback
    void notify(const Result &result);
    void notifyError(const err::Error &error);

    virtual VariantMap data() const {
        return {};
    }

    virtual void setData(const VariantMap &data) {
        (void)data;
    }

    Callback callback_; // Member to hold the callback function
    ErrorCallback errorCallback_;

    const std::string *registeredClassName_ = nullptr;
};

#define ACTION_CLASS(className) className::checkClassName(#className)

} // namespace cmd
} // namespace turnip

#endif // ACTION_H
