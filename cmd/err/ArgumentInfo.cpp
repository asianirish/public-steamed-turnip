#include "ArgumentInfo.h"

namespace turnip {
namespace cmd {
namespace err {

ArgumentInfo::ArgumentInfo() : ArgumentInfo(0, {}) {}

ArgumentInfo::ArgumentInfo(int argIndex, const std::string &argName)
    : argIndex_(argIndex), argName_(argName)
{}

int ArgumentInfo::argIndex() const
{
    return argIndex_;
}

void ArgumentInfo::setArgIndex(int newArgIndex)
{
    argIndex_ = newArgIndex;
}

std::string ArgumentInfo::argName() const
{
    return argName_;
}

void ArgumentInfo::setArgName(const std::string &newArgName)
{
    argName_ = newArgName;
}


} // namespace err
} // namespace cmd
} // namespace turnip
