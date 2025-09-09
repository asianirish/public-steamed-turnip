#ifndef ALWAYSFORBIDDEN_H
#define ALWAYSFORBIDDEN_H

#include "Constraint.h"

namespace turnip {
namespace cmd {
namespace def {

class AlwaysForbidden : public Constraint
{
public:
    AlwaysForbidden();

    bool isSatisfied(const Value &value) const;
    std::string description() const;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // ALWAYSFORBIDDEN_H
