#include "MissingRequiredArgumentInfo.h"

#include <sstream>

namespace turnip {
namespace cmd {
namespace err {

MissingRequiredArgumentInfo::MissingRequiredArgumentInfo() : MissingRequiredArgumentInfo(0, {}) {}

MissingRequiredArgumentInfo::MissingRequiredArgumentInfo(int argIndex, const std::string &argName)
    : ArgumentInfo(argIndex, argName)
{

}

std::string MissingRequiredArgumentInfo::description() const
{
    std::ostringstream oss;
    oss << "Argument [" << argIndex() << "]";
    if (!argName().empty()) {
        oss << " ('" << argName() << "')";
    }
    oss << " is missing. Please provide all required arguments or ensure that default values are properly defined.";
    return oss.str();
}



} // namespace err
} // namespace cmd
} // namespace turnip
