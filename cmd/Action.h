#ifndef ACTION_H
#define ACTION_H

#include "cmd/Types.h"
#include "def/ActionDef.h"
#include "err/Error.h"

#include <mutex>
#include <functional>

namespace turnip {
namespace cmd {

class Action
{
public:
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

private:
    virtual Value actImpl(const ArgList &args, err::Error &error) = 0;

    // Function to notify via callback
    void notify(const Value &result);
    void notifyError(const err::Error &error);

    std::mutex mutex_; // Protect shared resources
    Callback callback_; // Member to hold the callback function
    ErrorCallback errorCallback_;
};

} // namespace cmd
} // namespace turnip

#endif // ACTION_H
