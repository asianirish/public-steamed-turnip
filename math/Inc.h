#ifndef INC_H
#define INC_H

#include "cmd/UnaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

class Inc : public UnaryAction<int64_t, DecIntRep>
{
public:
    Inc();

private:
    int64_t unAct(const int64_t &arg, err::Error &error) override;
    std::string description() const override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // INC_H
