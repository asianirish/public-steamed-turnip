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
    Value(const VariantMap &vmp);

    Value(const VariantList &lst);

    Value(const std::vector<Value> &vec);

    Value(const TaskPtr &taskPtr);

    Value(const ActionPtr &action);

    template<typename T>
    Value(const std::shared_ptr<T>& action)
        : data_(std::static_pointer_cast<Action>(action))
    {
        // Ensure that T is derived from SyncAction
        static_assert(std::is_base_of<Action, T>::value, "T must be a derived class of Action");
    }
    // // TODO: or use a SFINAE approach
    // template<typename T>
    // Value(const std::shared_ptr<T>& action, typename std::enable_if<std::is_base_of<Action, T>::value>::type* = 0)
    //     : data_(std::static_pointer_cast<Action>(action)) {}



    ValueData data() const {
        return data_;
    }

    bool isNull() const;

    bool isTask() const;

    bool isMap() const;

    bool isString() const;

    bool isAction() const;

    // Conversion operator to std::string
    std::string toString() const;
    operator std::string() const;

    // Conversion operator to int
    int64_t toInt() const;
    operator int64_t() const;

    // Conversion operator to double
    double toDouble() const;
    operator double() const;


    // Conversion operator to bool
    bool toBool() const;
    operator bool() const;

    // Conversion operator to char
    char toChar() const;
    operator char() const;

    VariantMap toMap() const;
    operator VariantMap() const;

    ActionPtr toActionPtr() const;
    operator ActionPtr() const;

    TaskPtr toTaskPtr() const;
    operator TaskPtr() const;

private:
    ValueData data_;

    friend std::ostream& operator<<(std::ostream& os, const Value& value);
};

inline std::ostream& operator<<(std::ostream& os, const Value& value) {
    std::string stringValue = value;
    os << stringValue;
    return os;
}

inline Value operator"" _val(unsigned long long number) {
    return Value(static_cast<int64_t>(number));
}


inline Value operator"" _val(long double number) {
    return Value(static_cast<double>(number));
}


} // namespace cmd
} // namespace turnip

#endif // VALUE_H
