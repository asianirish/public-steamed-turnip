#include "ArgumentConversionInfo.h"

#include <sstream>

namespace turnip {
namespace cmd {
namespace err {

ArgumentConversionInfo::ArgumentConversionInfo() : ArgumentConversionInfo({}, {}, 0, {}) {}

ArgumentConversionInfo::ArgumentConversionInfo(const std::string &type, const std::string &input, int argIndex, const std::string &argName)
    : ArgumentInfo(argIndex, argName),
    type_(type),
    input_(input)
{

}

std::string ArgumentConversionInfo::type() const
{
    return type_;
}

void ArgumentConversionInfo::setType(const std::string &newType)
{
    type_ = newType;
}

std::string ArgumentConversionInfo::input() const
{
    return input_;
}

void ArgumentConversionInfo::setInput(const std::string &newInput)
{
    input_ = newInput;
}

std::string ArgumentConversionInfo::description() const
{
    std::ostringstream oss;
    oss << "Argument [" << argIndex() << "]";
    if (!argName().empty()) {
        oss << " ('" << argName() << "')";
    }
    oss << " of type '" << type() << "' failed to convert from input: '" << input() << "'.";
    oss << " Please ensure the input matches the expected type and format.";
    return oss.str();
}

} // namespace err
} // namespace cmd
} // namespace turnip
