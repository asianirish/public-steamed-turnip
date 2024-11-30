#ifndef CMD_TYPES_H
#define CMD_TYPES_H

#include "common/SharedMap.h"
#include "common/SharedVector.h"

#include <memory>
#include <vector>
#include <variant>

namespace turnip {
namespace cmd {

class Value;

using ArgList = std::vector<Value>;

using InputArgList = std::vector<std::string>;


class Action;
using ActionPtr = std::shared_ptr<Action>;


using VariantMap = common::SharedMap<std::string, Value>;
using VariantList =    common::SharedVector<Value>;

using ValueData = std::variant<std::monostate, bool, char, int64_t, double, std::string, VariantMap, VariantList>;

} // namespace cmd
} // namespace turnip

#endif // CMD_TYPES_H
