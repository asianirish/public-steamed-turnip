#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <string>

namespace turnip {
namespace cmd {

class Value;

namespace def {

class Constraint
{
public:
    Constraint();

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Constraint() = default;

    // Pure virtual method to check if a Value satisfies the constraint
    virtual bool isSatisfied(const Value& value) const = 0;

    // Pure virtual method to describe the constraint
    virtual std::string description() const = 0;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // CONSTRAINT_H
