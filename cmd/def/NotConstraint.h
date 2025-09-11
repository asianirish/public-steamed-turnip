#ifndef NOTCONSTRAINT_H
#define NOTCONSTRAINT_H

#include "Constraint.h"
#include "cmd/Types.h"

namespace turnip {
namespace cmd {
namespace def {

class NotConstraint : public Constraint
{
public:
    NotConstraint();

    bool isSatisfied(const Value &value) const override;
    std::string description() const override;

    ConPtr yesConstraint() const;
    void setYesConstraint(const ConPtr &newYesConstraint);

private:
    ConPtr yesConstraint_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // NOTCONSTRAINT_H
