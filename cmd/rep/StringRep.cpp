#include "StringRep.h"

namespace turnip {
namespace cmd {
namespace rep {

StringRep::StringRep() {}

Value StringRep::input(const std::string &str) const
{
    return inputImpl(str);
}

std::string StringRep::output(const Value &value) const
{
    return outputImpl(value);
}

def::MetaType StringRep::metaType() const
{
    return def::MetaType::String;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
