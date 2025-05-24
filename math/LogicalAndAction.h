#ifndef LOGICALANDACTION_H
#define LOGICALANDACTION_H

#include "cmd/BinaryAction.h"
#include "cmd/rep/BoolRep.h"

namespace turnip {
namespace cmd {
namespace math {

class LogicalAndAction : public BinaryAction<bool, rep::BoolRep>
{
public:
    LogicalAndAction();

private:
    virtual bool binAct(const bool &left, const bool &right, err::Error &error) override;
    std::string description() const override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // LOGICALANDACTION_H
