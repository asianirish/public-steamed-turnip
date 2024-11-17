#ifndef ACTION_H
#define ACTION_H

#include "cmd/Types.h"
#include "def/ActionDef.h"

#include <mutex>
#include <functional>
#include <future>

namespace turnip {
namespace cmd {

class Action
{
public:
    Action();
    virtual ~Action() = default;

    // Define a type for the callback function
    using Callback = std::function<void(const Value&)>;

    void setCallback(Callback callback);

    void act(const ArgList &args);

    virtual def::ActionDef actionDef() const = 0;

private:
    virtual Value actImpl(const ArgList &args) = 0;

    // Function to notify via callback
    void notify(const Value &result);

    std::mutex mutex_; // Protect shared resources
    Callback callback_; // Member to hold the callback function
};

} // namespace cmd
} // namespace turnip

#endif // ACTION_H
