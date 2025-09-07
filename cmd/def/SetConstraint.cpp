#include "SetConstraint.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace def {

SetConstraint::SetConstraint() {}

SetConstraint::SetConstraint(const std::set<Value> &acceptableValues)
    : acceptableValues_(acceptableValues) {}

SetConstraint::SetConstraint(std::initializer_list<Value> acceptableValues) /*: acceptableValues_(acceptableValues)*/ {}

bool SetConstraint::isSatisfied(const Value &value) const
{
    (void) value;
    return false;
    // TODO: To make this class work properly, you need to implement the `<` operator for the `Value` class.
    // return acceptableValues_.find(value) != acceptableValues_.end();
}

std::string SetConstraint::description() const
{
    return "Value must be one of the predefined acceptable values";
}

} // namespace def
} // namespace cmd
} // namespace turnip
