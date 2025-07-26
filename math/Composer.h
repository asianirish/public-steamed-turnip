#ifndef MATH_COMPOSER_H
#define MATH_COMPOSER_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {
namespace math {

// MathComposer
class Composer
{
public:
    static turnip::cmd::ActionPtr sineOfDegrees();

    static turnip::cmd::ActionPtr reverseDivide();

private:
    Composer();
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // MATH_COMPOSER_H
