#ifndef LOGICALNOTACTION_H
#define LOGICALNOTACTION_H

#include "cmd/UnaryAction.h"
#include "cmd/rep/BoolRep.h"

namespace turnip {
namespace cmd {
namespace math {

class LogicalNotAction : public UnaryAction<bool, rep::BoolRep>
{
public:
    LogicalNotAction();

private:
    bool unAct(const bool &arg, err::Error &error) override;
    std::string description() const override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // LOGICALNOTACTION_H
