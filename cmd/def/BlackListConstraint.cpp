#include "BlackListConstraint.h"
#include "cmd/Value.h"

#include <algorithm> // for std::find

namespace turnip {
namespace cmd {
namespace def {

BlackListConstraint::BlackListConstraint() {}

BlackListConstraint::BlackListConstraint(const std::vector<Value> &blackList)
    : blackList_(blackList) {}

BlackListConstraint::BlackListConstraint(std::initializer_list<Value> blackList)
    : blackList_(blackList) {}

bool BlackListConstraint::isSatisfied(const Value &value) const {
    // The value is satisfied if it is NOT found in the blacklist
    return std::find(blackList_.begin(), blackList_.end(), value) == blackList_.end();
}

std::string BlackListConstraint::description() const {
    return "Value must not be one of the predefined blacklisted values in the list";
}

} // namespace def
} // namespace cmd
} // namespace turnip
