#include "Result.h"

namespace turnip {
namespace cmd {

Result::Result() {}

Result::Result(const TaskId &taskId, const Value &value) :
    taskId_(taskId),
    value_(value)
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

} // namespace cmd
} // namespace turnip
