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
    using ArgErrorResultCallback = std::function<void(const cmd::err::Error &)>;

    ArgManager();

    bool execArgs(const ArgInfoList &argInfos);

    void onArgResult(const cmd::Result &result);
    void onArgError(const cmd::err::Error &error);

    void setArgResultsCallback(const ArgResultsCallback &newArgResultsCallback);

    void setArgErrorResultCallback(const ArgErrorResultCallback &newArgErrorResultCallback);

private:
    TaskManager taskManager_;
    std::map<TaskId, std::size_t> taskToArgNum_;
    ArgResults calculatedArgs_;
    ArgResultsCallback argResultsCallback_;
    ArgErrorResultCallback argErrorResultCallback_;
};

} // namespace cmd
} // namespace turnip

#endif // ARGMANAGER_H
