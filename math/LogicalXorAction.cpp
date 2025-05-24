#include "LogicalXorAction.h"

namespace turnip {
namespace cmd {
namespace math {

LogicalXorAction::LogicalXorAction() {}

bool LogicalXorAction::binAct(const bool &left, const bool &right, err::Error &error)
{
    (void)error;
    return (left && !right) || (!left && right);
}

std::string LogicalXorAction::description() const
{
    return "XOR";
}



} // namespace math
} // namespace cmd
} // namespace turnip
