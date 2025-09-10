#ifndef INTGREATERCONSTRAINT_H
#define INTGREATERCONSTRAINT_H

#include "Constraint.h"
#include <cstdint>

namespace turnip {
namespace cmd {
namespace def {

class IntGreaterConstraint : public Constraint
{
public:
    IntGreaterConstraint();
    IntGreaterConstraint(int64_t greaterThenValue);

    bool isSatisfied(const Value &value) const override;
    std::string description() const override;

    int64_t greaterThenValue() const;
    void setGreaterThenValue(int64_t newGreaterThenValue);

private:
    int64_t greaterThenValue_ {INT64_MIN};
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // INTGREATERCONSTRAINT_H
