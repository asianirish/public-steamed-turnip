#ifndef INSTANCESAFEACTION_H
#define INSTANCESAFEACTION_H

#include "SafeAction.h"

namespace turnip {
namespace cmd {

class InstanceSafeAction : public SafeAction
{
public:
    InstanceSafeAction();

private:
    mutable std::mutex mutex_;

    std::mutex &mutex() const override;
};

} // namespace cmd
} // namespace turnip

#endif // INSTANCESAFEACTION_H
