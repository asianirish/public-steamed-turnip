#include "NullRep.h"

namespace turnip {
namespace cmd {
namespace rep {

NullRep::NullRep() {}

Value NullRep::input(const std::string &str) const
{
    (void)str;
    return Value();
}

std::string NullRep::output(const Value &value) const
{
    (void)value;
    return nullString_;
}

std::string NullRep::nullString() const
{
    return nullString_;
}

void NullRep::setNullString(const std::string &newNull_string)
{
    nullString_ = newNull_string;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
