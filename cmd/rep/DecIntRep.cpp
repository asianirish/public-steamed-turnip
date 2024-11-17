#include "DecIntRep.h"

namespace turnip {
namespace cmd {
namespace rep {

DecIntRep::DecIntRep() {}

int64_t DecIntRep::inputImpl(const std::string &str)
{
    try {
        std::size_t pos;
        int64_t number = std::stoll(str, &pos);
        if (pos != str.length()) {
            throw std::invalid_argument("Invalid input: not a complete integer");
        }
        return number;
    } catch (const std::exception &e) {
        throw std::invalid_argument("Invalid input: " + std::string(e.what()));
    }
}

std::string DecIntRep::outputImpl(int64_t number)
{
    return std::to_string(number);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
