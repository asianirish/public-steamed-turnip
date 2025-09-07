#include "ListConstraint.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace def {

ListConstraint::ListConstraint() {}

ListConstraint::ListConstraint(const std::vector<Value> &acceptableValues)
    : acceptableValues_(acceptableValues) {}

ListConstraint::ListConstraint(std::initializer_list<Value> acceptableValues)
    : acceptableValues_(acceptableValues) {}

bool ListConstraint::isSatisfied(const Value &value) const {
    (void) value;
    return false;
    // TODO: To make this class work properly, you need to implement the `==` operator for the `Value` class.
    // return std::find(acceptableValues_.begin(), acceptableValues_.end(), value) != acceptableValues_.end();
}

std::string ListConstraint::description() const {
    return "Value must be one of the predefined acceptable values in the list";
}

} // namespace def
} // namespace cmd
} // namespace turnip
