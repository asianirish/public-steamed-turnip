#include "StringRep.h"

namespace turnip {
namespace cmd {
namespace rep {

StringRep::StringRep() {}

Value StringRep::input(const std::string &str)
{
    return inputImpl(str);
}

std::string StringRep::output(const Value &value)
{
    return outputImpl(value);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
