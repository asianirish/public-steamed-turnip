#include "NotEqConstrain.h"

namespace turnip {
namespace cmd {
namespace def {

NotEqConstrain::NotEqConstrain() {}

bool NotEqConstrain::isSatisfied(const Value &value) const
{
    return (value != notEqValue_);
}

std::string NotEqConstrain::description() const
{
    return "Not Equal";
}

Value NotEqConstrain::notEqValue() const
{
    return notEqValue_;
}

void NotEqConstrain::setNotEqValue(const Value &newNotEqValue)
{
    notEqValue_ = newNotEqValue;
}

} // namespace def
} // namespace cmd
} // namespace turnip
