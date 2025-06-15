#include "WhileAction.h"

#include "cmd/PrintAction.h"
#include "math/Id.h"
#include "loop/ActionEvState.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

using namespace def;
using namespace math;

WhileAction::WhileAction() {

    auto defaultAction = mkActionPtr(PrintAction);
    auto defaultArgList = ArgList{"0"};
    defaultTask_ = mkPtr<Task>(defaultAction, defaultArgList);

    auto defaultEvAction = mkActionPtr(StrId);
    auto defaultEvArgList = ArgList{true};
    defaultEvTask_ = mkPtr<Task>(defaultEvAction, defaultEvArgList);
}

def::ActionDef WhileAction::actionDef() const
{
    ActionDef actionDef;

    const auto taskDef = TypeDef::createTaskTypedef();
    const auto intDef = TypeDef::createIntTypedef();

    {
        ArgDef argDef;
        argDef.setType(taskDef);
        argDef.setName("task");
        argDef.setDefaultValue(defaultTask_);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(taskDef);
        argDef.setName("evTask");
        argDef.setDefaultValue(defaultEvTask_);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(taskDef);
        argDef.setName("resultArgIndex");
        argDef.setDefaultValue(loop::ActionEvState::INVALID_RESULT_INDEX);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(taskDef);
        argDef.setName("resultEvArgIndex");
        argDef.setDefaultValue(loop::ActionEvState::INVALID_RESULT_INDEX);
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

void WhileAction::emitRequest(const TaskId &taskId, const ArgList &args)
{
    auto task = args.at(0).toTaskPtr();
    auto evTask = args.at(1).toTaskPtr();
    auto resultArgIndex = args.at(2).toInt();
    auto resultEvArgIndex = args.at(3).toInt();

    auto state = mkPtr<loop::ActionEvState>(&stateManager_, taskId,
                                            task->actionPtr(), task->argList(),
                                            evTask->actionPtr(), evTask->argList());

    state->setResultArgumentIndex(resultArgIndex);
    state->setResultEvArgumentIndex(resultEvArgIndex);

    {
        auto f = std::bind(&WhileAction::onResult, this, std::placeholders::_1);
        state->setResultCallback(f);
    }
    // TODO: error callback

    state->start();
}

void WhileAction::emitComplete(const Value &reslutValue, const TaskId &taskId)
{
    // TODO: implement
    (void) reslutValue;
    (void) taskId;
}

void WhileAction::onResult(const Result &result)
{
    notify(result);
    emitComplete(result.value(), result.taskId());
}

} // namespace cmd
} // namespace turnip
