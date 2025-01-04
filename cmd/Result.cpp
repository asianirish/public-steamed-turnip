#include "Result.h"
#include "cmd/rep/RepresentationManager.h"

namespace turnip {
namespace cmd {

Result::Result() {}

Result::Result(const TaskId &taskId, const Value &value, const rep::Representation *representation) :
    taskId_(taskId),
    value_(value),
    representation_(representation)
{

}

TaskId Result::taskId() const
{
    return taskId_;
}

void Result::setTaskId(TaskId newTaskId)
{
    taskId_ = newTaskId;
}

Value Result::value() const
{
    return value_;
}

void Result::setValue(const Value &newValue)
{
    value_ = newValue;
}

void Result::setRepresentation(const std::string &repKey)
{
    representation_ = rep::RepresentationManager::representation(repKey);
}

const rep::Representation *Result::representation() const
{
    return representation_;
}

} // namespace cmd
} // namespace turnip
