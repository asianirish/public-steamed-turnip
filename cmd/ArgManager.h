#ifndef ARGMANAGER_H
#define ARGMANAGER_H

#include "cmd/TaskManager.h"

namespace turnip {
namespace cmd {

class ArgManager
{
public:
    ArgManager();

    bool execArgs(const ArgInfoList &argInfos);

    void onArgResult(const cmd::Result &result);
    void onArgError(const cmd::err::Error &error);

private:
    TaskManager taskManager_;
    std::map<TaskId, std::size_t> taskToArgNum_;
};

} // namespace cmd
} // namespace turnip

#endif // ARGMANAGER_H
