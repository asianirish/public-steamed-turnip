#include "IntGreaterConstraint.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace def {

IntGreaterConstraint::IntGreaterConstraint() {}

IntGreaterConstraint::IntGreaterConstraint(int64_t greaterThenValue) : greaterThenValue_(greaterThenValue)
{

}

bool IntGreaterConstraint::isSatisfied(const Value &value) const
{
    return (value.toInt() > greaterThenValue_);
}

std::string IntGreaterConstraint::description() const
{
    return "Greater Then " + std::to_string(greaterThenValue_);;
}

int64_t IntGreaterConstraint::greaterThenValue() const
{
    return greaterThenValue_;
}

void IntGreaterConstraint::setGreaterThenValue(int64_t newGreaterThenValue)
{
    greaterThenValue_ = newGreaterThenValue;
}

} // namespace def
} // namespace cmd
} // namespace turnip
