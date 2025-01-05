#ifndef TASKIDGENERATOR_H
#define TASKIDGENERATOR_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {

class TaskIdGenerator
{
public:
    TaskIdGenerator();

    virtual void init() = 0;
    virtual TaskId next() = 0;
};

} // namespace cmd
} // namespace turnip

#endif // TASKIDGENERATOR_H
