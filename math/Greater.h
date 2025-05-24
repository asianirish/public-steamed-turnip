#ifndef GREATER_H
#define GREATER_H

#include "cmd/CmpAction.h"

namespace turnip {
namespace cmd {
namespace math {

template<typename T, typename Rep>
class Greater : public CmpAction<T, Rep>
{
public:
    Greater() {}

private:
    virtual bool cmpAct(const T &left, const T &right, err::Error &error) final;
    virtual std::string description() const override;
};

template<typename T, typename Rep>
bool Greater<T, Rep>::cmpAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return (left > right);
}

template<typename T, typename Rep>
std::string Greater<T, Rep>::description() const
{
    return "is less";
}

using GreaterInt = Greater<int64_t, DecIntRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // GREATER_H
