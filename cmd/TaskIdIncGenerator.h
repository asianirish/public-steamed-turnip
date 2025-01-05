#ifndef TASKIDINCGENERATOR_H
#define TASKIDINCGENERATOR_H

#include "TaskIdGenerator.h"

namespace turnip {
namespace cmd {

class TaskIdIncGenerator : public TaskIdGenerator
{
public:
    static const TaskId FIRST_TASK_ID = 1024;

    TaskIdIncGenerator();

    void init() override;
    TaskId next() final;

private:
    TaskId maxTaskId_;
};

} // namespace cmd
} // namespace turnip

#endif // TASKIDINCGENERATOR_H
