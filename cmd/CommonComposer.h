#ifndef COMMONCOMPOSER_H
#define COMMONCOMPOSER_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {

class CommonComposer
{
public:
    static ActionPtr lessOrEqual();
private:
    CommonComposer();
};

} // namespace cmd
} // namespace turnip

#endif // COMMONCOMPOSER_H
