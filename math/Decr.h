#ifndef DECR_H
#define DECR_H

#include "cmd/UnaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

class Decr : public UnaryAction<int64_t, DecIntRep>
{
public:
    Decr();

private:
    int64_t unAct(const int64_t &arg, err::Error &error) override;
    std::string description() const override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // DECR_H
