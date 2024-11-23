#include "HexIntRep.h"

#include <sstream>

namespace turnip {
namespace cmd {
namespace rep {

HexIntRep::HexIntRep() {}

std::string HexIntRep::outputImpl(int64_t number)
{
    std::stringstream ss;
    ss << std::hex << number;
    return ss.str();
}

} // namespace rep
} // namespace cmd
} // namespace turnip
