#ifndef VALUE_H
#define VALUE_H

#include "common/SharedMap.h"

#include <variant>

namespace turnip {
namespace cmd {

class Value;

using ValueData = std::variant<std::monostate, bool, char, int64_t, double, std::string, common::SharedMap<std::string, Value>>;

class Value
{
public:
    Value();

    Value(bool yes);

    Value(char c);

    Value(int n);

    Value(int64_t n);

    Value(double d);

    Value(const std::string &str);

    Value(const char *str);

    Value(const std::map<std::string, Value> &mp);

    ValueData data() const {
        return data_;
    }

    bool isNull() const;

    // Conversion operator to std::string
    operator std::string() const;

    // Conversion operator to int
    operator int64_t() const;

    // Conversion operator to double
    operator double() const;


    // Conversion operator to bool
    operator bool() const;

    // Conversion operator to char
    operator char() const;

private:
    ValueData data_;

    friend std::ostream& operator<<(std::ostream& os, const Value& value);
};

inline std::ostream& operator<<(std::ostream& os, const Value& value) {
    std::visit([&os](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            os << "invalid";
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
        } else if constexpr (std::is_same_v<T, common::SharedMap<std::string, Value>>) {
            os << "{ ";
            for (const auto& [key, val] : arg) {
                os << key << ": " << val << ", ";
            }
            os << " }";
        }
    }, value.data_);
    return os;
}

} // namespace cmd
} // namespace turnip

#endif // VALUE_H
