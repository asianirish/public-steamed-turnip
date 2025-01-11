#include "Error.h"
#include "AdditionalInfo.h"
#include "cmd/err/ArgumentConversionInfo.h"
#include "cmd/err/CommandNotFoundInfo.h"
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

Error Error::createTaskError(const TaskId &taskId, const std::string &description, std::shared_ptr<AdditionalInfo> additionalInfo)
{
    return Error(ErrorType::Custom, description, additionalInfo, taskId);
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

Error Error::createCommandNotFoundError(const std::string &commandName)
{
    return Error(ErrorType::CommandNotFound, {},
                 std::shared_ptr<AdditionalInfo>(new CommandNotFoundInfo(commandName)));
}

Error::Error(ErrorType type, const std::string& description, std::shared_ptr<AdditionalInfo> additionalInfo, const TaskId &taskId)
    : type_(type), description_(description), additionalInfo_(additionalInfo), taskId_(taskId) {}

bool Error::maybeSetAdditionalInfo(const std::shared_ptr<AdditionalInfo> &newAdditionalInfo)
{
    if (type_ == ErrorType::Custom) {
        additionalInfo_ = newAdditionalInfo;
        return true;
    }

    return false;
}

std::optional<TaskId> Error::maybeTaskId() const
{
    if (type_ == ErrorType::Custom) {
        return taskId_;
    }

    return {};
}

bool Error::maybeSetTaskId(const TaskId &taskId)
{
    if (type_ == ErrorType::Custom) {
        taskId_ = taskId;
        return true;
    }

    return false;
}

bool Error::maybeSetDescription(const std::string &newDescription)
{
    if (type_ == ErrorType::Custom) {
        description_ = newDescription;
        return true;
    }

    return false;
}

} // namespace err
} // namespace cmd
} // namespace turnip
