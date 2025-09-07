#ifndef LISTCONSTRAINT_H
#define LISTCONSTRAINT_H

#include "Constraint.h"

#include <vector>
#include <algorithm>

namespace turnip {
namespace cmd {
namespace def {

class ListConstraint : public Constraint
{
public:
    ListConstraint();

    // Constructor that takes a vector of acceptable values
    ListConstraint(const std::vector<Value>& acceptableValues);

    // Constructor that takes an initializer list of acceptable values
    ListConstraint(std::initializer_list<Value> acceptableValues);

    // Check if the provided Value is within the acceptable list
    bool isSatisfied(const Value& value) const override;

    // Describe the constraint
    std::string description() const override;

private:
    std::vector<Value> acceptableValues_; // List of acceptable values
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // LISTCONSTRAINT_H
