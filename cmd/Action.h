#ifndef ACTION_H
#define ACTION_H

#include "cmd/Types.h"
#include "def/ActionDef.h"
#include "err/Error.h"

#include <mutex>
#include <functional>

namespace turnip {
namespace cmd {

// TODO: Specify the return type (representation of the expected value)
class Action
{
public:
    static const std::string CLASS_NAME_KEY;
    static const std::string DATA_KEY;

    Action();
    virtual ~Action() = default;

    // Define a type for the callback function
    using Callback = std::function<void(const Value&)>;
    using ErrorCallback = std::function<void(const err::Error&)>;

    void setCallback(Callback callback);

    void act(const ArgList &args);

    virtual def::ActionDef actionDef() const = 0;

    void setErrorCallback(const ErrorCallback &newErrorCallback);

    virtual bool isAsync() const {
        return true;
    }

    // should not be used directly
    static std::string checkClassName(const std::string &className) {
        return className;
    }

    std::string registeredClassName() const;
    void setRegisteredClassName(const std::string *newRegisteredClassName);

    VariantMap toMap() const;

private:
    virtual Value actImpl(const ArgList &args, err::Error &error) = 0;

    // Function to notify via callback
    void notify(const Value &result);
    void notifyError(const err::Error &error);

    virtual VariantMap data() const {
        return {};
    }

    Callback callback_; // Member to hold the callback function
    ErrorCallback errorCallback_;

    const std::string *registeredClassName_ = nullptr;
};

#define ACTION_CLASS(className) className::checkClassName(#className)

} // namespace cmd
} // namespace turnip

#endif // ACTION_H
