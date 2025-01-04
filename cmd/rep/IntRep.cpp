#include "IntRep.h"
#include "cmd/err/ConversionException.h"

namespace turnip {
namespace cmd {
namespace rep {

IntRep::IntRep() {}

Value IntRep::input(const std::string &str) const
{
    return inputImpl(str);
}

std::string IntRep::output(const Value &value) const
{
    return outputImpl(value);
}

int64_t IntRep::inputImpl(const std::string &str) const
{
    try {
        std::size_t pos;
        int64_t number = std::stoll(str, &pos, base());
        return number;
    } catch (const std::exception &e) {
        throw err::ConversionException("int", str);
    }
}

} // namespace rep
} // namespace cmd
} // namespace turnip
