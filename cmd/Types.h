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

template<typename T>
using Ptr = std::shared_ptr<T>;

template <typename T, typename... Args>
inline std::shared_ptr<T> mkPtr(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

class Value;

using ArgList = std::vector<Value>;

using InputArgList = std::vector<std::string>;


class Action;
using ActionPtr = std::shared_ptr<Action>;
using LazyAction = common::LazyPointer<Action>;

#define mkActionPtr(A) ActionPtr(common::Factory<Action>::create(ACTION_CLASS(A)))
#define mkDynActionPtr(A) std::dynamic_pointer_cast<A>(mkActionPtr(A))


using VariantMap = common::SharedMap<std::string, Value>;
using VariantList =    common::SharedVector<Value>;

using TaskId = size_t;

class Task;
using TaskPtr = std::shared_ptr<Task>;

using ValueData = std::variant<std::monostate, bool, char, int64_t, double, std::string, VariantMap, VariantList, TaskPtr, ActionPtr>;

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

namespace rep {
class Representation;
using RepPtr = std::shared_ptr<Representation>;

#define mkRepPtr(R) RepPtr(common::Factory<Representation>::create(REPRESENTATION_CLASS(R)))
#define mkDynRepPtr(R) std::dynamic_pointer_cast<R>(mkRepPtr(R))

} // namespace rep

namespace loop {

class State;
using StatePtr = std::shared_ptr<State>;

using StateId = TaskId;

} // namespace loop

} // namespace cmd
} // namespace turnip

#endif // CMD_TYPES_H
