#include "AsyncCompositeAction.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

AsyncCompositeAction::AsyncCompositeAction() {}

def::ActionDef AsyncCompositeAction::actionDef() const
{
    return actionDef_;
}


void AsyncCompositeAction::setActionDef(const def::ActionDef &newActionDef)
{
    actionDef_ = newActionDef;
}

bool AsyncCompositeAction::doStartInThread() const
{
    return false; // TODO: ?
}

Substitutor AsyncCompositeAction::substitutor() const
{
    return substitutor_;
}

void AsyncCompositeAction::onSubTaskComplete(const Value &reslutValue, const TaskId &taskId)
{
    emitComplete(reslutValue, taskId);
}

void AsyncCompositeAction::setAction(const ActionPtr &action)
{
    substitutor_.setActionParam(action);
}

void AsyncCompositeAction::setAction(const Alias &alias)
{
    substitutor_.setActionParam(alias);
}

void AsyncCompositeAction::addParam(int position)
{
    substitutor_.addParam(Parameter(position));
}

void AsyncCompositeAction::addParam(const Value &value)
{
    substitutor_.addParam(Parameter(value));
}

void AsyncCompositeAction::addParam(const ActionPtr &action)
{
    substitutor_.addParam(Parameter(action));
}

void AsyncCompositeAction::addParam(const ActionPtr &action, const ParamList &paramList)
{
    substitutor_.addParam(Parameter(action, paramList));
}

void AsyncCompositeAction::addParam(const Alias &alias, const ParamList &paramList)
{
    substitutor_.addParam(Parameter(alias, paramList));
}

void AsyncCompositeAction::addParams(const ParamList &paramList)
{
    for (const auto &param : paramList) {
        substitutor_.addParam(param);
    }
}

void AsyncCompositeAction::emitRequest(const TaskId &taskId, const ArgList &args)
{
    auto task = substitutor_.substitue(args);

#ifdef DEBUG_ACTION_ARGS
    for (auto &arg : args) {
        std::cout << std::endl << "ASYNC COMPOSITE ARG: " << arg.toString() << std::endl;
    }
#endif

#ifdef DEBUG_ACTION_TASKS
    std::cout << std::endl << "ASYNC_COMPOSITE_ACTION INNER TASK: " << task->taskId() << std::endl;
    std::cout << "ASYNC_COMPOSITE_ACTION  THIS TASK:" << taskId << std::endl;
#endif

    // TODO: emit task
    auto rep = actionDef().resultRepresentation();
    Result result(taskId, task, rep);
    notify(result);
}

void AsyncCompositeAction::emitComplete(const Value &reslutValue, const TaskId &taskId)
{
    // TODO: implement
    std::cout << std::endl << "ASYNC COMPOSITE RESULT IS: " << reslutValue << " " << taskId << std::endl;
}


} // namespace cmd
} // namespace turnip
