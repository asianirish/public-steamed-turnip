#ifndef BLACKLISTCONSTRAINT_H
#define BLACKLISTCONSTRAINT_H

#include "Constraint.h"
#include <vector>

namespace turnip {
namespace cmd {
namespace def {

class BlackListConstraint : public Constraint
{
public:
    BlackListConstraint();

    // Constructor that takes a vector of blacklisted values
    BlackListConstraint(const std::vector<Value>& blackList);

    // Constructor that takes an initializer list of blacklisted values
    BlackListConstraint(std::initializer_list<Value> blackList);

    // Check if the provided Value is not within the blacklist
    bool isSatisfied(const Value& value) const override;

    // Describe the constraint
    std::string description() const override;

private:
    std::vector<Value> blackList_; // List of blacklisted values
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // BLACKLISTCONSTRAINT_H
