#ifndef INTRANGECONSTRAINT_H
#define INTRANGECONSTRAINT_H

#include "Constraint.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace def {

class IntRangeConstraint : public Constraint
{
public:
    IntRangeConstraint();

    IntRangeConstraint(int64_t min, int64_t max); // : min_(min), max_(max) {}

    bool isSatisfied(const Value& value) const override;

    std::string description() const override;

private:
    int64_t min_ {INT64_MIN};
    int64_t max_ {INT64_MAX};
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // INTRANGECONSTRAINT_H
