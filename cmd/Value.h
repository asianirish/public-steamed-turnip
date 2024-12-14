#ifndef VALUE_H
#define VALUE_H

#include "cmd/Types.h"

#include <iostream>


namespace turnip {
namespace cmd {

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

    Value(const std::vector<Value> &vec);

    Value(const TaskPtr &taskPtr);

    Value(const LazyAction &action);

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
    std::string stringValue = value;
    os << stringValue;
    return os;
}

} // namespace cmd
} // namespace turnip

#endif // VALUE_H
