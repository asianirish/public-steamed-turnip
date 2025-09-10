#ifndef NOTEQCONSTRAIN_H
#define NOTEQCONSTRAIN_H

#include "Constraint.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace def {

class NotEqConstrain : public Constraint
{
public:
    NotEqConstrain();

    bool isSatisfied(const Value &value) const override;
    std::string description() const override;

    Value notEqValue() const;
    void setNotEqValue(const Value &newNotEqValue);

private:
    Value notEqValue_ {0};
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // NOTEQCONSTRAIN_H
