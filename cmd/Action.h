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
    static const std::string DATA_KEY;
    static const std::string CLASS_NAME_KEY;

    // Define a type for the callback function
    using Callback = std::function<void(const Result&)>;
    using ErrorCallback = std::function<void(const err::Error&)>;

    virtual ~Action() = default;

    void act(const TaskId &taskId, const ArgList &args);

    void setCallback(Callback callback);
    void setErrorCallback(const ErrorCallback &newErrorCallback);

    std::string registeredClassName() const;
    void setRegisteredClassName(const std::string *newRegisteredClassName);

    VariantMap toMap() const;
    static ActionPtr fromMap(const VariantMap &mp);

    ActionPtr clone() const;

    virtual VariantMap data() const {
        return {};
    }

    virtual void setData(const VariantMap &data) {
        (void)data;
    }

    // should not be used directly
    static std::string checkClassName(const std::string &className) {
        return className;
    }

    virtual def::ActionDef actionDef() const = 0;

    virtual bool doStartInThread() const = 0;

protected:
    virtual void specificAct(const TaskId &taskId, const ArgList &args) = 0;

    // Function to notify via callback
    void notify(const Result &result);
    void notifyError(const err::Error &error);

private:
    const std::string *registeredClassName_ = nullptr;

    Callback callback_; // Member to hold the callback function
    ErrorCallback errorCallback_;
};

#define ACTION_CLASS(className) className::checkClassName(#className)

} // namespace cmd
} // namespace turnip

#endif // ACTION_H
