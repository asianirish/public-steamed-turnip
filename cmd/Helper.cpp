#include "Helper.h"

#include <algorithm>

namespace turnip {
namespace cmd {

Helper::Helper() {}

std::vector<std::string> Helper::toStringVector(const std::vector<Value> &values, std::vector<std::string> &resultVector)
{
    resultVector.reserve(values.size());

    std::transform(values.cbegin(), values.cend(),
                   std::back_inserter(resultVector), // output iterator std::back_inserter(resultVector)
                   [](const Value &value) {
                       return value.toString();
                    }
                   );
    return resultVector;
}

} // namespace cmd
} // namespace turnip
