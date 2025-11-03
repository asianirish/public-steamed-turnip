#ifndef TURNIP_COMMON_HELPER_H
#define TURNIP_COMMON_HELPER_H

#include <cstddef>

namespace turnip {
namespace common {

class Helper
{
public:
    Helper();

    // TODO: use to reserve memory for vectors used in StdComboContainer, DynComboContainer and ExComboContainer
    static size_t ipow(size_t base, size_t exp);
};

} // namespace common
} // namespace turnip

#endif // TURNIP_COMMON_HELPER_H
