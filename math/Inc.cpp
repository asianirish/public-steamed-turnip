#include "Inc.h"

namespace turnip {
namespace cmd {
namespace math {

Inc::Inc() {}

int64_t Inc::unAct(const int64_t &arg, err::Error &error)
{
    (void)error;
    return arg + 1;
}

std::string Inc::description() const
{
    return "Increment";
}

} // namespace math
} // namespace cmd
} // namespace turnip
