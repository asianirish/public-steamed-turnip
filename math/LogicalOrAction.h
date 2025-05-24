#ifndef LOGICALORACTION_H
#define LOGICALORACTION_H

#include "cmd/BinaryAction.h"
#include "cmd/rep/BoolRep.h"

namespace turnip {
namespace cmd {
namespace math {

class LogicalOrAction : public BinaryAction<bool, rep::BoolRep>
{
public:
    LogicalOrAction();

private:
    virtual bool binAct(const bool &left, const bool &right, err::Error &error) override;
    std::string description() const override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // LOGICALORACTION_H
