#ifndef ADDACTION_H
#define ADDACTION_H

#include "cmd/BinaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

using namespace def;

template<typename T, typename Rep>
class AddAction : public BinaryAction<T, Rep>
{
public:
    AddAction() {};

private:
    virtual T binAct(const T &left, const T &right, err::Error &error) override;
    std::string description() const override;
};

template<typename T, typename Rep>
T AddAction<T, Rep>::binAct(const T &left, const T &right, err::Error &error)
{
    (void)error;
    return left + right;
}

template<typename T, typename Rep>
std::string AddAction<T, Rep>::description() const
{
    return "Add";
}

using AddInt = AddAction<int64_t, DecIntRep>;
using AddFloat = AddAction<double, DoubleRep>;
using Concat = AddAction<std::string, SimpleStringRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // ADDACTION_H
