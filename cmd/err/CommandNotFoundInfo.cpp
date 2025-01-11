#include "CommandNotFoundInfo.h"

#include <sstream>

namespace turnip {
namespace cmd {
namespace err {

CommandNotFoundInfo::CommandNotFoundInfo() : CommandNotFoundInfo(std::string{}) {}

CommandNotFoundInfo::CommandNotFoundInfo(const std::string &commandName) :
    commandName_(commandName)
{

}

std::string CommandNotFoundInfo::description() const
{
    std::ostringstream oss;
    oss << "The command '" << commandName_ << "' could not be found. Please check the command and try again";
    return oss.str();
}

} // namespace err
} // namespace cmd
} // namespace turnip
