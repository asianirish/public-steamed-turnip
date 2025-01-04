#include "CharRep.h"

namespace turnip {
namespace cmd {
namespace rep {

CharRep::CharRep() {}

Value CharRep::input(const std::string &str) const
{
    return inputImpl(str);
}

std::string CharRep::output(const Value &value) const
{
    return outputImpl(value);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
