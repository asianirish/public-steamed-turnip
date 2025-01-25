#ifndef MULTACTION_H
#define MULTACTION_H

#include "cmd/BinaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

template<typename T, typename Rep>
class MultAction : public BinaryAction<T, Rep>
{
public:
    MultAction() {};

private:
    virtual T binAct(const T &left, const T &right, err::Error &error) override;
    std::string description() const override;
};

template<typename T, typename Rep>
T MultAction<T, Rep>::binAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return left * right;
}

template<typename T, typename Rep>
std::string MultAction<T, Rep>::description() const
{
    return "Mult";
}

using MultInt = MultAction<int64_t, DecIntRep>;
using MultFloat = MultAction<double, DoubleRep>;


} // namespace math
} // namespace cmd
} // namespace turnip

#endif // MULTACTION_H
