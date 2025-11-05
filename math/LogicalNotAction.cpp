#include "LogicalNotAction.h"

namespace turnip {
namespace cmd {
namespace math {

LogicalNotAction::LogicalNotAction() {}

bool LogicalNotAction::unAct(const bool &arg, err::Error &error)
{
    (void) error;
    return !arg;
}

std::string LogicalNotAction::description() const
{
    return "NOT";
}

} // namespace math
} // namespace cmd
} // namespace turnip
