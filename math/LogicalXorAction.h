#ifndef LOGICALXORACTION_H
#define LOGICALXORACTION_H

#include "cmd/BinaryAction.h"
#include "cmd/rep/BoolRep.h"

namespace turnip {
namespace cmd {
namespace math {

class LogicalXorAction : public BinaryAction<bool, rep::BoolRep>
{
public:
    LogicalXorAction();

private:
    virtual bool binAct(const bool &left, const bool &right, err::Error &error) override;
    std::string description() const override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // LOGICALXORACTION_H
