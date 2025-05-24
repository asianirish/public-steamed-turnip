#ifndef LESS_H
#define LESS_H

#include "cmd/CmpAction.h"

namespace turnip {
namespace cmd {
namespace math {

template<typename T, typename Rep>
class Less : public CmpAction<T, Rep>
{
public:
    Less() {}

private:
    virtual bool cmpAct(const T &left, const T &right, err::Error &error) final;
    virtual std::string description() const override;
};

template<typename T, typename Rep>
bool Less<T, Rep>::cmpAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return (left < right);
}

template<typename T, typename Rep>
std::string Less<T, Rep>::description() const
{
    return "is less";
}

using LessInt = Less<int64_t, DecIntRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // LESS_H
