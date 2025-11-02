#ifndef HELPER_H
#define HELPER_H

#include "cmd/Value.h"

namespace turnip {
namespace cmd {

class Helper
{
public:
    Helper();

    static std::vector<std::string> toStringVector(const std::vector<Value> &values, std::vector<std::string> &resultVector);
};

} // namespace cmd
} // namespace turnip

#endif // HELPER_H
