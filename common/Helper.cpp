#include "Helper.h"

namespace turnip {
namespace common {

Helper::Helper() {}

size_t Helper::ipow(size_t base, size_t exp)
{
    size_t result = 1;
    while (true) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
    return result;
}

} // namespace common
} // namespace turnip
