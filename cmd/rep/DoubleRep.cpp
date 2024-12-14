#include "DoubleRep.h"

#include <sstream>

namespace turnip {
namespace cmd {
namespace rep {

DoubleRep::DoubleRep() {}

Value DoubleRep::input(const std::string &str)
{
    return inputImpl(str);
}

std::string DoubleRep::output(const Value &value)
{
    return outputImpl(value);
}

std::string DoubleRep::classKey() const
{
    return "default_double";
}

double DoubleRep::inputImpl(const std::string &str)
{
    return std::stod(str);
}

std::string DoubleRep::outputImpl(double number)
{
    std::ostringstream oss;
    oss.precision(precision()); // Sets the precision to precision() significant digits
    oss << std::fixed << number; // Use std::fixed to avoid scientific notation
    return oss.str();
}

std::streamsize DoubleRep::precision() const
{
    return 3;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
