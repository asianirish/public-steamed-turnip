#ifndef RESULT_H
#define RESULT_H

#include "cmd/Types.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {

class Result
{
public:
    Result();
    Result(const TaskId &taskId, const Value &value);

    TaskId taskId() const;
    void setTaskId(TaskId newTaskId);

    Value value() const;
    void setValue(const Value &newValue);

private:
    TaskId taskId_;
    Value value_;
};

} // namespace cmd
} // namespace turnip

#endif // RESULT_H
