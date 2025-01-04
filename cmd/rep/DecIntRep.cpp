#include "DecIntRep.h"
#include "cmd/err/ConversionException.h"

namespace turnip {
namespace cmd {
namespace rep {

DecIntRep::DecIntRep() {}

std::string DecIntRep::outputImpl(int64_t number) const
{
    return std::to_string(number);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
