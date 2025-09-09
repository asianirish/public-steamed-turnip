#include "AlwaysForbidden.h"

namespace turnip {
namespace cmd {
namespace def {

AlwaysForbidden::AlwaysForbidden() {}

bool AlwaysForbidden::isSatisfied(const Value &value) const
{
    (void) value;

    return false;
}

std::string AlwaysForbidden::description() const
{
    return "No Constraint";
}

} // namespace def
} // namespace cmd
} // namespace turnip
