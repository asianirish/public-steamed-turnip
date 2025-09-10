#ifndef INTLESSCONSTRAINT_H
#define INTLESSCONSTRAINT_H

#include "Constraint.h"
#include <cstdint>

namespace turnip {
namespace cmd {
namespace def {

class IntLessConstraint : public Constraint
{
public:
    IntLessConstraint();
    IntLessConstraint(int64_t lessThenValue);

    bool isSatisfied(const Value &value) const override;
    std::string description() const override;

    int64_t lessThenValue() const;
    void setLessThenValue(int64_t newLessThenValue);

private:
    int64_t lessThenValue_ {INT64_MAX};
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // INTLESSCONSTRAINT_H
