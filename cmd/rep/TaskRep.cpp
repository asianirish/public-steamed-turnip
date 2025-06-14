#include "TaskRep.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {
namespace rep {

TaskRep::TaskRep() {}

Value TaskRep::input(const std::string &str) const
{
    return str;
}

std::string TaskRep::output(const Value &value) const
{
    TaskPtr task = value.toTaskPtr();
    if (task) {
        return std::string("TaskId: ") + std::to_string(task->taskId());
    }

    return {};
}

std::string TaskRep::repKey() const
{
    return "default";
}

def::MetaType TaskRep::metaType() const
{
    return def::MetaType(def::MetaType::Type::Task);
}

} // namespace rep
} // namespace cmd
} // namespace turnip
