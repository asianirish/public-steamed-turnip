#ifndef ERROR_H
#define ERROR_H

#include "cmd/Types.h"

#include <memory>
#include <string>
#include <optional>

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
        CommandNotFound,
        Custom = 65635
    };

    std::string description() const;

    static Error createUndefinedError();

    static Error createCustomError(const std::string& description = {}, std::shared_ptr<AdditionalInfo> additionalInfo = nullptr);

    static Error createTaskError(const TaskId &taskId, const std::string& description = {}, std::shared_ptr<AdditionalInfo> additionalInfo = nullptr);

    static Error createMissingRequiredArgumentError(int argIndex, const std::string &argName);

    static Error createArgumentConversionError(const std::string& type, const std::string& input, int argIndex, const std::string &argName);

    static Error createCommandNotFoundError(const std::string &commandName);

    bool maybeSetDescription(const std::string &newDescription);

    bool maybeSetAdditionalInfo(const std::shared_ptr<AdditionalInfo> &newAdditionalInfo);

    std::optional<TaskId> maybeTaskId() const;
    bool maybeSetTaskId(const TaskId &taskId);

private:
    // Private constructor to enforce the use of factory functions
    Error(ErrorType type, const std::string& description, std::shared_ptr<AdditionalInfo> additionalInfo = nullptr, const TaskId &taskId = 0);

    ErrorType type_;
    std::string description_;
    std::shared_ptr<AdditionalInfo> additionalInfo_;

    TaskId taskId_ {0};

};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // ERROR_H
