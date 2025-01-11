#ifndef ARGMANAGER_H
#define ARGMANAGER_H

#include "cmd/TaskManager.h"

namespace turnip {
namespace cmd {

class ArgManager
{
public:
    // Define a type for the callback function
    using ArgResultsCallback = std::function<void(const ArgResults&)>;

    ArgManager();

    bool execArgs(const ArgInfoList &argInfos);

    void onArgResult(const cmd::Result &result);
    void onArgError(const cmd::err::Error &error);

    void setArgResultsCallback(const ArgResultsCallback &newArgResultsCallback);

private:
    TaskManager taskManager_;
    std::map<TaskId, std::size_t> taskToArgNum_;
    ArgResults calculatedArgs_;
    ArgResultsCallback argResultsCallback_;

};

} // namespace cmd
} // namespace turnip

#endif // ARGMANAGER_H
