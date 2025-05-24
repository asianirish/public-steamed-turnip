#include "LogicalAndAction.h"

namespace turnip {
namespace cmd {
namespace math {

LogicalAndAction::LogicalAndAction() {}

bool LogicalAndAction::binAct(const bool &left, const bool &right, err::Error &error)
{
    (void)error;
    return (left && right);
}

std::string LogicalAndAction::description() const
{
    return "AND";
}

} // namespace math
} // namespace cmd
} // namespace turnip
