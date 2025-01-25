#ifndef SUBACTION_H
#define SUBACTION_H

#include "cmd/BinaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

template<typename T, typename Rep>
class SubAction : public BinaryAction<T, Rep>
{
public:
    SubAction() {};

private:
    virtual T binAct(const T &left, const T &right, err::Error &error) override;
    std::string description() const override;
};

template<typename T, typename Rep>
T SubAction<T, Rep>::binAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return left - right;
}

template<typename T, typename Rep>
std::string SubAction<T, Rep>::description() const
{
    return "Subtract";
}

using SubInt = SubAction<int64_t, DecIntRep>;
using SubFloat = SubAction<double, DoubleRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // SUBACTION_H
