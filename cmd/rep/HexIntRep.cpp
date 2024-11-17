#include "HexIntRep.h"

#include <sstream>

namespace turnip {
namespace cmd {
namespace rep {

HexIntRep::HexIntRep() {}

int64_t HexIntRep::inputImpl(const std::string &str)
{
    try {
        std::size_t pos;
        int64_t number = std::stoll(str, &pos, 16);
        if (pos != str.length()) {
            throw std::invalid_argument("Invalid input: not a complete hexadecimal integer");
        }
        return number;
    } catch (const std::exception &e) {
        throw std::invalid_argument("Invalid input: " + std::string(e.what()));
    }
}

std::string HexIntRep::outputImpl(int64_t number)
{
    std::stringstream ss;
    ss << std::hex << number;
    return ss.str();
}

} // namespace rep
} // namespace cmd
} // namespace turnip
