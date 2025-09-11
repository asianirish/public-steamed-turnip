#include "NotConstraint.h"

namespace turnip {
namespace cmd {
namespace def {

NotConstraint::NotConstraint() {}

bool NotConstraint::isSatisfied(const Value &value) const
{
    if (yesConstraint_) {
        return !yesConstraint_->isSatisfied(value);
    }

    return false;
}

std::string NotConstraint::description() const
{
    if (yesConstraint_) {
        return "NOT " + yesConstraint_->description();
    }

    return "NOT";
}

ConPtr NotConstraint::yesConstraint() const
{
    return yesConstraint_;
}

void NotConstraint::setYesConstraint(const ConPtr &newYesConstraint)
{
    yesConstraint_ = newYesConstraint;
}

} // namespace def
} // namespace cmd
} // namespace turnip
