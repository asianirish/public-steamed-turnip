#ifndef CONVERSIONEXCEPTION_H
#define CONVERSIONEXCEPTION_H

#include <stdexcept>

namespace turnip {
namespace cmd {
namespace err {

class ConversionException : public std::runtime_error
{
public:
    // Constructor that takes the type of conversion and the invalid string
    ConversionException(const std::string& type, const std::string& input);

    std::string type() const;

    std::string input() const;

private:
    std::string type_;
    std::string input_;
};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // CONVERSIONEXCEPTION_H
