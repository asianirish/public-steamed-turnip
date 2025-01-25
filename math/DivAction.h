#ifndef DIVACTION_H
#define DIVACTION_H

#include "cmd/BinaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

template<typename T, typename Rep>
class DivAction : public BinaryAction<T, Rep>
{
public:
    DivAction() {};

private:
    virtual T binAct(const T &left, const T &right, err::Error &error) override;
    std::string description() const override;
};

template<typename T, typename Rep>
T DivAction<T, Rep>::binAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return left / right;
}

template<typename T, typename Rep>
std::string DivAction<T, Rep>::description() const
{
    return "Divide";
}

using DivInt = DivAction<int64_t, DecIntRep>;
using DivFloat = DivAction<double, DoubleRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // DIVACTION_H
