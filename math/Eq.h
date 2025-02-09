#ifndef EQ_H
#define EQ_H

#include "cmd/CmpAction.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

template<typename T, typename Rep>
class Eq : public CmpAction<T, Rep>
{
public:
    Eq() {}

private:
    virtual bool cmpAct(const T &left, const T &right, err::Error &error) final;
    virtual std::string description() const override;
};

template<typename T, typename Rep>
bool Eq<T, Rep>::cmpAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return (left == right);
}

template<typename T, typename Rep>
std::string Eq<T, Rep>::description() const
{
    return "is equal";
}

using EqInt = Eq<int64_t, DecIntRep>;


} // namespace math
} // namespace cmd
} // namespace turnip

#endif // EQ_H
