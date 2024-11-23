#include "ConversionException.h"

namespace turnip {
namespace cmd {
namespace err {

ConversionException::ConversionException(const std::string& type, const std::string& input)
    : std::runtime_error("Failed to convert string '" + input + "' to " + type + "."),
    type_(type),
    input_(input)
{}

std::string ConversionException::type() const
{
    return type_;
}

std::string ConversionException::input() const
{
    return input_;
}

} // namespace err
} // namespace cmd
} // namespace turnip
