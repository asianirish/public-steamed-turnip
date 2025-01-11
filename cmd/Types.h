#ifndef CMD_TYPES_H
#define CMD_TYPES_H

#include "common/SharedMap.h"
#include "common/SharedVector.h"
#include "common/LazyPointer.h"

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
using LazyAction = common::LazyPointer<Action>;


using VariantMap = common::SharedMap<std::string, Value>;
using VariantList =    common::SharedVector<Value>;

using TaskId = size_t;

class Task;
using TaskPtr = std::shared_ptr<Task>;

using ValueData = std::variant<std::monostate, bool, char, int64_t, double, std::string, VariantMap, VariantList, TaskPtr, LazyAction>;

class Parameter;
using ParamList = common::SharedVector<Parameter>;


enum class ExecType {
    Auto,
    Direct,
    Thread,
    // Async, // for future use
};

class ArgInfo;
using ArgInfoList = std::vector<ArgInfo>;


using ArgResults = std::map<std::size_t, Value>;

} // namespace cmd
} // namespace turnip

#endif // CMD_TYPES_H
