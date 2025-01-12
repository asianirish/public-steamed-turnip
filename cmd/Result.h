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
    Result(const TaskId &taskId, const Value &value, const rep::RepPtr &representation);

    TaskId taskId() const;
    void setTaskId(TaskId newTaskId);

    Value value() const;
    void setValue(const Value &newValue);

    bool isTask() const;

    rep::RepPtr representation() const;
    void setRepresentation(const rep::RepPtr &newRepresentation);

private:
    TaskId taskId_;
    Value value_;
    rep::RepPtr representation_;
};

} // namespace cmd
} // namespace turnip

#endif // RESULT_H
