#include "Error.h"
#include "AdditionalInfo.h"
#include "cmd/err/ArgumentConversionInfo.h"
#include "cmd/err/MissingRequiredArgumentInfo.h"

namespace turnip {
namespace cmd {
namespace err {

std::string Error::description() const
{
    if (additionalInfo_) {
        return additionalInfo_->description();
    }

    return description_;
}

Error Error::createUndefinedError()
{
    return Error(ErrorType::Undefined, "Undefined error");
}

Error Error::createCustomError(const std::string &description, std::shared_ptr<AdditionalInfo> additionalInfo)
{
    return Error(ErrorType::Custom, description, additionalInfo);
}

Error Error::createMissingRequiredArgumentError(int argIndex, const std::string &argName)
{
    return Error(ErrorType::MissingRequiredArgument, {},
                 std::shared_ptr<MissingRequiredArgumentInfo>(new MissingRequiredArgumentInfo(argIndex, argName)));
}

Error Error::createArgumentConversionError(const std::string &type, const std::string &input, int argIndex, const std::string &argName)
{
    return Error(ErrorType::ArgumentConversion, {},
                 std::shared_ptr<ArgumentConversionInfo>(new ArgumentConversionInfo(type, input, argIndex, argName)));
}

Error::Error(ErrorType type, const std::string& description, std::shared_ptr<AdditionalInfo> additionalInfo)
    : type_(type), description_(description), additionalInfo_(additionalInfo) {}

void Error::setAdditionalInfo(const std::shared_ptr<AdditionalInfo> &newAdditionalInfo)
{
    if (type_ == ErrorType::Custom) {
        additionalInfo_ = newAdditionalInfo;
    }
    // TODO: else
    // TODO: throw an exception otherwise
}

void Error::setDescription(const std::string &newDescription)
{
    if (type_ == ErrorType::Custom) {
        description_ = newDescription;
    }
    // TODO: else
    // TODO: throw an exception otherwise
}

} // namespace err
} // namespace cmd
} // namespace turnip
