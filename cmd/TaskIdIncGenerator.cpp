#include "TaskIdIncGenerator.h"

namespace turnip {
namespace cmd {

TaskIdIncGenerator::TaskIdIncGenerator() :
    maxTaskId_(FIRST_TASK_ID) {}

void TaskIdIncGenerator::init()
{
    maxTaskId_ = FIRST_TASK_ID;
}

TaskId TaskIdIncGenerator::next()
{
    return maxTaskId_++;
}



} // namespace cmd
} // namespace turnip
