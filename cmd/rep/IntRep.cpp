#include "IntRep.h"

namespace turnip {
namespace cmd {
namespace rep {

IntRep::IntRep() {}

Value IntRep::input(const std::string &str)
{
    return inputImpl(str);
}

std::string IntRep::output(const Value &value)
{
    return outputImpl(value);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
