#include "LogicalOrAction.h"

namespace turnip {
namespace cmd {
namespace math {

LogicalOrAction::LogicalOrAction() {}

bool LogicalOrAction::binAct(const bool &left, const bool &right, err::Error &error)
{
    (void)error;
    return (left || right);
}

std::string LogicalOrAction::description() const
{
    return "OR";
}

} // namespace math
} // namespace cmd
} // namespace turnip
