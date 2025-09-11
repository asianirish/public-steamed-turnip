#ifndef ANDCONSTRAINT_H
#define ANDCONSTRAINT_H

#include "Constraint.h"
#include "cmd/Types.h"

#include <vector>

namespace turnip {
namespace cmd {
namespace def {

class AndConstraint : public Constraint
{
public:
    AndConstraint();

    bool isSatisfied(const Value &value) const override;
    std::string description() const override;

    std::vector<ConPtr> constraints() const;
    void addConstraint(const ConPtr &constraint);

private:
    std::vector<ConPtr> constraints_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // ANDCONSTRAINT_H
