#include "Decr.h"

namespace turnip {
namespace cmd {
namespace math {

Decr::Decr() {}

int64_t Decr::unAct(const int64_t &arg, err::Error &error)
{
    (void)error;
    return arg - 1;
}

std::string Decr::description() const
{
    return "Decrement";
}

} // namespace math
} // namespace cmd
} // namespace turnip
