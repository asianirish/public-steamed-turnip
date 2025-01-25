#ifndef SAFEACTION_H
#define SAFEACTION_H

#include "Action.h"

#include <mutex>

namespace turnip {
namespace cmd {

class SafeAction : public Action
{
public:
    SafeAction();

private:
    Value actImpl(const ArgList &args, err::Error &error) final;

    virtual Value actSafely(const ArgList &args, err::Error &error) = 0;

    virtual std::mutex &mutex() const = 0;
};

} // namespace cmd
} // namespace turnip

#endif // SAFEACTION_H
