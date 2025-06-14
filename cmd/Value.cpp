#include "Value.h"
#include "Task.h"
#include "SyncAction.h"
#include "math/Id.h"

#include <sstream>
#include <algorithm>

namespace turnip {
namespace cmd {

using namespace math;

Value::Value() {}

Value::Value(bool yes) : data_(yes)
{

}

Value::Value(char c) : data_(c)
{

}

Value::Value(int n) : data_(n)
{

}

Value::Value(int64_t n) : data_(n)
{

}

Value::Value(double d) : data_(d)
{

}

Value::Value(const std::string &str) : data_(str)
{

}

Value::Value(const char *str) : data_(str)
{

}

Value::Value(const std::map<std::string, Value> &mp) : data_(mp)
{

}

Value::Value(const VariantMap &vmp) : data_(vmp)
{

}

Value::Value(const VariantList &lst) : data_(lst)
{

}

Value::Value(const std::vector<Value> &vec) : data_(vec)
{

}

Value::Value(const TaskPtr &taskPtr) : data_(taskPtr)
{

}

Value::Value(const ActionPtr &action) : data_(action)
{

}

bool Value::isNull() const
{
    return std::holds_alternative<std::monostate>(data_);
}

bool Value::isTask() const
{
    return std::holds_alternative<TaskPtr>(data_);
}

bool Value::isMap() const
{
    return std::holds_alternative<VariantMap>(data_);
}

bool Value::isString() const
{
    return std::holds_alternative<std::string>(data_);
}

bool Value::isAction() const
{
    return std::holds_alternative<ActionPtr>(data_);
}

std::string Value::toString() const
{
    std::ostringstream os;
    std::visit([&os](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            os << "null";
        } else if constexpr (std::is_same_v<T, bool>) {
            os << (arg ? "true" : "false");
        } else if constexpr (std::is_same_v<T, char>) {
            os << arg;
        } else if constexpr (std::is_same_v<T, int64_t>) {
            os << arg;
        } else if constexpr (std::is_same_v<T, double>) {
            os << arg;
        } else if constexpr (std::is_same_v<T, std::string>) {
            os << arg;
        } else if constexpr (std::is_same_v<T, VariantMap>) {
            os << "{";
            for (auto it = arg.begin(); it != arg.end(); ++it) {
                if (it != arg.begin()) {
                    os << ", ";
                }
                os << "\"" << it->first << "\": " << std::string(it->second);
            }
            os << "}";
        } else if constexpr (std::is_same_v<T, VariantList>) {
            os << "[";
            for (auto it = arg.begin(); it != arg.end(); ++it) {
                if (it != arg.begin()) {
                    os << ", ";
                }
                os << std::string(*it);  // Assuming Value has a suitable operator std::string()
            }
            os << "]";
        } else if constexpr (std::is_same_v<T, TaskPtr>) {
            Value taskMapValue = arg->toMap();
            VariantMap mp;
            mp.set("type", "Task");
            mp.set("data", taskMapValue);
            Value taskValue(mp);
            os << taskValue.toString();
        } else if constexpr (std::is_same_v<T, ActionPtr>) {
            Value actionMapValue = arg->toMap();
            VariantMap mp;
            mp.set("type", "Action");
            mp.set("data", actionMapValue);
            Value actionValue(mp);
            os << actionValue.toString();
        }
    }, data_);
    return os.str();
}

Value::operator std::string() const
{
    return toString();
}

int64_t Value::toInt() const
{
    return std::visit([](auto&& arg) -> int64_t {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            return 0;  // or throw an exception if you want.
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? 1 : 0;
        } else if constexpr (std::is_same_v<T, char>) {
            return static_cast<int64_t>(arg);
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return arg;
        } else if constexpr (std::is_same_v<T, double>) {
            return static_cast<int64_t>(arg);
        } else if constexpr (std::is_same_v<T, std::string>) {
            try {
                return std::stoll(arg);
            } catch (...) {
                return 0; // or handle the exception as preferred
            }
        } else if constexpr (std::is_same_v<T, VariantMap>) {
            return 0; // or throw an exception since a map can't be directly converted to int64_t
        } else if constexpr (std::is_same_v<T, VariantList>) {
            return 0; // or throw an exception since a map can't be directly converted to int64_t
        } else if constexpr (std::is_same_v<T, TaskPtr>) {
            return 0; // or throw an exception since a TaskPtr can't be directly converted to int64_t
        } else if constexpr (std::is_same_v<T, ActionPtr>) {
            return 0; // or throw an exception since a LazyPtr can't be directly converted to int64_t
        }
    }, data_);
}

Value::operator int64_t() const
{
    return toInt();
}

double Value::toDouble() const
{
    return std::visit([](auto&& arg) -> double {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            return 0.0;  // Consider `std::monostate` as zero.
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? 1.0 : 0.0;  // Convert `bool` to 1.0 or 0.0.
        } else if constexpr (std::is_same_v<T, char>) {
            return static_cast<double>(arg);  // Convert char to double.
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return static_cast<double>(arg);  // Convert integer to double.
        } else if constexpr (std::is_same_v<T, double>) {
            return arg;  // Direct conversion if already a double.
        } else if constexpr (std::is_same_v<T, std::string>) {
            try {
                return std::stod(arg);  // Convert string to double.
            } catch (...) {
                return 0.0;  // Handle conversion failure, default to zero.
            }
        } else if constexpr (std::is_same_v<T, VariantMap>) {
            return 0.0;  // Maps can't be directly converted to a double, default to zero.
        } else if constexpr (std::is_same_v<T, VariantList>) {
            return 0.0; // Lists can't be directly converted to a double, default to zero.
        } else if constexpr (std::is_same_v<T, TaskPtr>) {
            return 0.0; // or throw an exception since a TaskPtr can't be directly converted to double
        } else if constexpr (std::is_same_v<T, ActionPtr>) {
            return 0.0; // or throw an exception since a TaskPtr can't be directly converted to double
        }
    }, data_);
}

Value::operator double() const
{
    return toDouble();
}

bool Value::toBool() const
{
    return std::visit([](auto&& arg) -> bool {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            return false;  // Consider `null` as `false`.
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg;  // Direct conversion if already a boolean.
        } else if constexpr (std::is_same_v<T, char>) {
            return arg != 0;  // Non-zero characters are `true`.
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return arg != 0;  // Non-zero integers are `true`.
        } else if constexpr (std::is_same_v<T, double>) {
            return arg != 0.0;  // Non-zero doubles are `true`.
        } else if constexpr (std::is_same_v<T, std::string>) {
            // Convert "false" string to boolean false.
            std::string lower_arg = arg;
            std::transform(lower_arg.begin(), lower_arg.end(), lower_arg.begin(), ::tolower);
            if (lower_arg == "false") {
                return false;
            }
            return !arg.empty();  // Non-empty strings are generally `true`.
        } else if constexpr (std::is_same_v<T, VariantMap>) {
            return !arg.empty();  // Non-empty maps are `true`.
        } else if constexpr (std::is_same_v<T, VariantList>) {
            return !arg.empty();  // Non-empty lists are `true`.
        } else if constexpr (std::is_same_v<T, TaskPtr>) {
            return static_cast<bool>(arg);
        } else if constexpr (std::is_same_v<T, ActionPtr>) {
            return static_cast<bool>(arg);
        }
    }, data_);
}

Value::operator bool() const
{
    return toBool();
}

char Value::toChar() const
{
    return std::visit([](auto&& arg) -> char {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            return '\0';  // Consider `std::monostate` as the null character.
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? '1' : '0';  // Convert `bool` to '1' or '0'.
        } else if constexpr (std::is_same_v<T, char>) {
            return arg;  // Direct conversion if already a char.
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return static_cast<char>(arg);  // Convert integer to char.
        } else if constexpr (std::is_same_v<T, double>) {
            return static_cast<char>(arg);  // Convert double to char.
        } else if constexpr (std::is_same_v<T, std::string>) {
            return !arg.empty() ? arg.front() : '\0';  // Use first character of non-empty string.
        } else if constexpr (std::is_same_v<T, VariantMap>) {
            return '\0';  // Maps can't be directly converted to a char, returning null character.
        } else if constexpr (std::is_same_v<T, VariantList>) {
            return '\0';  // Lists can't be directly converted to a char, returning null character.
        } else if constexpr (std::is_same_v<T, TaskPtr>) {
            return '\0';  // TaskPtr can't be directly converted to a char, returning null character.
        } else if constexpr (std::is_same_v<T, ActionPtr>) {
            return '\0';  // TaskPtr can't be directly converted to a char, returning null character.
        }
    }, data_);
}

Value::operator char() const
{
    return toChar();
}

VariantMap Value::toMap() const
{
    if (isMap()) {
        return std::get<VariantMap>(data_);
    } else if (isAction()) {
        auto action = toActionPtr();
        return action->toMap();
    }

    return {};
}

Value::operator VariantMap() const
{
    return toMap();
}

ActionPtr Value::toActionPtr() const
{
    if (isAction()) {
        return std::get<ActionPtr>(data_);
    }

    if (isMap()) {
        auto mp = toMap();
        auto action = Action::fromMap(mp);
        return action;
    }


    return nullptr;
}

Value::operator ActionPtr() const
{
    return toActionPtr();
}

TaskPtr Value::toTaskPtr() const
{
    if (isTask()) {
        return std::get<TaskPtr>(data_);
    }

    // TODO: from map (?)

    // neither task nor map of tasks
    TaskPtr taskPtr(new Task());
    auto idAction = mkActionPtr(StrId);
    taskPtr->setActionPtr(idAction);

    auto value = std::get<std::string>(data_);
    taskPtr->setArgList({value});

    return taskPtr;
}

Value::operator TaskPtr() const
{
    return toTaskPtr();
}

} // namespace cmd
} // namespace turnip
