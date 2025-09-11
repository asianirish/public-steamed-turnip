#include "AndConstraint.h"

namespace turnip {
namespace cmd {
namespace def {

AndConstraint::AndConstraint() {}

bool AndConstraint::isSatisfied(const Value &value) const
{
    for (const auto& constraint : constraints_) {
        if (!constraint->isSatisfied(value)) {
            return false; // If any constraint is not satisfied, return false
        }
    }
    return true; // All constraints are satisfied
}

std::string AndConstraint::description() const
{
    std::string desc = "AndConstraint: (";
    for (size_t i = 0; i < constraints_.size(); ++i) {
        desc += constraints_[i]->description();
        if (i < constraints_.size() - 1) {
            desc += " AND ";
        }
    }
    desc += ")";
    return desc;
}

std::vector<ConPtr> AndConstraint::constraints() const
{
    return constraints_;
}

void AndConstraint::addConstraint(const ConPtr &constraint)
{
    constraints_.push_back(constraint);
}

} // namespace def
} // namespace cmd
} // namespace turnip
