#include "RemAction.h"

namespace turnip {
namespace cmd {
namespace math {

RemAction::RemAction() {}

int64_t RemAction::binAct(int64_t left, int64_t right, err::Error &error)
{
    (void)error;
    return left % right;
}

std::string RemAction::description() const
{
    return "Remainder";
}

} // namespace math
} // namespace cmd
} // namespace turnip
