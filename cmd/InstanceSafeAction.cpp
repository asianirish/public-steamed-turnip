#include "InstanceSafeAction.h"

namespace turnip {
namespace cmd {

InstanceSafeAction::InstanceSafeAction() {}

std::mutex &InstanceSafeAction::mutex() const
{
    return mutex_;
}

} // namespace cmd
} // namespace turnip
