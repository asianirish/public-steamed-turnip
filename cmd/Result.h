#ifndef RESULT_H
#define RESULT_H

#include "cmd/Types.h"
#include "cmd/Value.h"
#include "cmd/rep/Representation.h"

namespace turnip {
namespace cmd {

class Result
{
public:
    Result();
    Result(const TaskId &taskId, const Value &value, const rep::Representation *representation);

    TaskId taskId() const;
    void setTaskId(TaskId newTaskId);

    Value value() const;
    void setValue(const Value &newValue);

    void setRepresentation(const std::string &repKey);
    const rep::Representation *representation() const;

    bool isTask() const;

private:
    TaskId taskId_;
    Value value_;
    const rep::Representation *representation_ = 0;
};

} // namespace cmd
} // namespace turnip

#endif // RESULT_H
