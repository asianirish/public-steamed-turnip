#ifndef NOTEQ_H
#define NOTEQ_H

#include "cmd/CmpAction.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

template<typename T, typename Rep>
class NotEq : public CmpAction<T, Rep>
{
public:
    NotEq() {}

private:
    virtual bool cmpAct(const T &left, const T &right, err::Error &error) final;
    virtual std::string description() const override;
};

template<typename T, typename Rep>
bool NotEq<T, Rep>::cmpAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return (left != right);
}

template<typename T, typename Rep>
std::string NotEq<T, Rep>::description() const
{
    return "not equal";
}

using NotEqInt = NotEq<int64_t, DecIntRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // NOTEQ_H
