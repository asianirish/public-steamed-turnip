#ifndef ERROR_H
#define ERROR_H

#include <memory>
#include <string>

namespace turnip {
namespace cmd {
namespace err {

class AdditionalInfo;

class Error
{
public:
    // Enumeration for different types of errors
    enum class ErrorType {
        Undefined,
        MissingRequiredArgument,
        ArgumentConversion,
        Custom = 65635
    };

    std::string description() const;

    static Error createUndefinedError();

    static Error createCustomError(const std::string& description, std::shared_ptr<AdditionalInfo> additionalInfo = nullptr);

    static Error createMissingRequiredArgumentError(int argIndex, const std::string &argName);

    static Error createArgumentConversionError(const std::string& type, const std::string& input, int argIndex, const std::string &argName);

private:
    // Private constructor to enforce the use of factory functions
    Error(ErrorType type, const std::string& description, std::shared_ptr<AdditionalInfo> additionalInfo = nullptr);

    ErrorType type_;
    std::string description_;
    std::shared_ptr<AdditionalInfo> additionalInfo_;
};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // ERROR_H
