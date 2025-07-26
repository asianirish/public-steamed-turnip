#ifndef CONST_H
#define CONST_H

#include <cstddef>

namespace turnip {
namespace cmd {

class Const
{
public:
    static const size_t ARG_MAX {1024};

private:
    Const();
};

} // namespace cmd
} // namespace turnip

#endif // CONST_H
