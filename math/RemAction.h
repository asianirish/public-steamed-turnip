#ifndef REMACTION_H
#define REMACTION_H

#include "cmd/BinaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

class RemAction : public BinaryAction<int64_t, DecIntRep>
{
public:
    RemAction();

private:
    int64_t binAct(int64_t left, int64_t right, err::Error &error) override;
    std::string description() const override;
};


} // namespace math
} // namespace cmd
} // namespace turnip

#endif // REMACTION_H
