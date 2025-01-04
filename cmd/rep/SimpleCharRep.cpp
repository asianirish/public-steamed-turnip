#include "SimpleCharRep.h"

namespace turnip {
namespace cmd {
namespace rep {

SimpleCharRep::SimpleCharRep() {}

char SimpleCharRep::inputImpl(const std::string &str) const
{
    if (str.empty()) {
        return '\0';
    }

    return str.at(0);
}

std::string SimpleCharRep::outputImpl(char character) const
{
    return std::string(1, character);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
