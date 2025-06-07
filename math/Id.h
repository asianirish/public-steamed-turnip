#ifndef ID_H
#define ID_H

#include "cmd/UnaryAction.h"

namespace turnip {
namespace cmd {
namespace math {

template<typename T, typename Rep>
class Id : public UnaryAction<T, Rep>
{
public:
    Id() {}

    bool doStartInThread() const final {
        return false;
    }

private:
    T unAct(const T &arg, err::Error &error) override;
    std::string description() const override;
};

template<typename T, typename Rep>
inline T Id<T, Rep>::unAct(const T &arg, err::Error &error)
{
    (void) error;
    return arg;
}

template<typename T, typename Rep>
inline std::string Id<T, Rep>::description() const
{
    return "Id";
}

using StrId = Id<std::string, SimpleStringRep>;

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // ID_H
