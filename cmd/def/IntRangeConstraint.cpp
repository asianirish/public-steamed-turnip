#include "IntRangeConstraint.h"

namespace turnip {
namespace cmd {
namespace def {

IntRangeConstraint::IntRangeConstraint() {}

IntRangeConstraint::IntRangeConstraint(int64_t min, int64_t max) : min_(min), max_(max)
{

}

bool IntRangeConstraint::isSatisfied(const Value &value) const
{
    // TODO:
    // if (!value.isInt()) {
    //     return false;
    // }

    int64_t intValue = value.toInt();
    return intValue >= min_ && intValue <= max_;
}

std::string IntRangeConstraint::description() const
{
    return "Value must be an integer between " + std::to_string(min_) + " and " + std::to_string(max_);
}

} // namespace def
} // namespace cmd
} // namespace turnip
