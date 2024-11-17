#include "SimpleStringRep.h"

namespace turnip {
namespace cmd {
namespace rep {

SimpleStringRep::SimpleStringRep() {}

std::string SimpleStringRep::inputImpl(const std::string &str)
{
    return str;
}

std::string SimpleStringRep::outputImpl(const std::string &stringValue)
{
    return stringValue;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
