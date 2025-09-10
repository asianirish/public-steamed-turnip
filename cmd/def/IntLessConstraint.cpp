#include "IntLessConstraint.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace def {

IntLessConstraint::IntLessConstraint() {}

IntLessConstraint::IntLessConstraint(int64_t lessThenValue) : lessThenValue_(lessThenValue)
{

}

bool IntLessConstraint::isSatisfied(const Value &value) const
{
    return (value.toInt() < lessThenValue_);
}

std::string IntLessConstraint::description() const
{
    return "Less Then";
}

int64_t IntLessConstraint::lessThenValue() const
{
    return lessThenValue_;
}

void IntLessConstraint::setLessThenValue(int64_t newLessThenValue)
{
    lessThenValue_ = newLessThenValue;
}

} // namespace def
} // namespace cmd
} // namespace turnip
