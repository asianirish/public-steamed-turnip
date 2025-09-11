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
    return std::find(acceptableValues_.begin(), acceptableValues_.end(), value) != acceptableValues_.end();
}

std::string ListConstraint::description() const {
    std::string desc("Value must be one of the predefined acceptable values in the list: [");

    int i = 0;
    for (const auto &value : acceptableValues_) {
        if (i) {
            desc += ", ";
        }
        desc += value.toString();
        ++i;
    }
    desc += "]";

    return desc;
}

} // namespace def
} // namespace cmd
} // namespace turnip
