#include "Result.h"

namespace turnip {
namespace cmd {

Result::Result() {}

Result::Result(const TaskId &taskId, const Value &value, const rep::RepPtr &representation) :
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

bool Result::isTask() const
{
    return value_.isTask();
}

rep::RepPtr Result::representation() const
{
    return representation_;
}

void Result::setRepresentation(const rep::RepPtr &newRepresentation)
{
    representation_ = newRepresentation;
}

} // namespace cmd
} // namespace turnip
