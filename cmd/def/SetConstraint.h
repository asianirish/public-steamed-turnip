#ifndef SETCONSTRAINT_H
#define SETCONSTRAINT_H

#include "Constraint.h"

#include <set>
#include <initializer_list>

namespace turnip {
namespace cmd {
namespace def {


class [[deprecated("To make this class work properly, you need to implement the `<` operator for the `Value` class.")]] SetConstraint : public Constraint
{
public:
    SetConstraint();

    // Constructor that takes a set of acceptable values
    SetConstraint(const std::set<Value>& acceptableValues);

    // Constructor that takes an initializer list of acceptable values
    SetConstraint(std::initializer_list<Value> acceptableValues);

    // Check if the provided Value is within the acceptable set
    bool isSatisfied(const Value& value) const override;

    // Describe the constraint
    std::string description() const override;

private:
    std::set<Value> acceptableValues_; // Set of acceptable values
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // SETCONSTRAINT_H
