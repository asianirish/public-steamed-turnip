#include "ForAction.h"
#include "cmd/PrintAction.h"
#include "cmd/loop/IncState.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

using namespace def;

ForAction::ForAction() {

    if (!defaultTask_) {
        auto defaultAction = mkActionPtr(PrintAction);
        auto defaultArgList = ArgList({"0"});
        defaultTask_ = mkPtr<Task>(defaultAction, defaultArgList);
    } else {
        std::cout << std::endl << "DEBUG DEFAULT TASK IS ALREADY DEFINED" << std::endl;
    }
}

def::ActionDef ForAction::actionDef() const
{
    ActionDef actionDef;

    const auto intDef = TypeDef::createIntTypedef();
    const auto taskDef = TypeDef::createTaskTypedef();

    {
        ArgDef argDef;
        argDef.setType(intDef);
        argDef.setName("upTo");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(intDef);
        argDef.setName("initial");
        argDef.setDesc("Initial counter value");
        argDef.setDefaultValue(0);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(intDef);
        argDef.setName("counterIndex");
        argDef.setDesc("Counter Index");
        argDef.setDefaultValue(0);
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(taskDef);
        argDef.setName("task");
        argDef.setDefaultValue(defaultTask_);
        actionDef.addArgDef(argDef);
    }

    const auto boolDef = TypeDef::createBoolTypedef();
    {
        ArgDef argDef;
        argDef.setType(intDef);
        argDef.setName("isInclusive");
        argDef.setDesc("Is Inclusive");
        argDef.setDefaultValue(false);
        actionDef.addArgDef(argDef);
    }


    return actionDef;
}

void ForAction::emitRequest(const TaskId &taskId, const ArgList &args)
{
    auto upTo = args.at(0).toInt();
    auto counter = args.at(1).toInt();
    auto counterIndex = args.at(2).toInt();
    auto task = args.at(3).toTaskPtr();
    auto isInclusive = args.at(4).toBool();

    auto state = mkPtr<loop::IncState>(&stateManager_, taskId, task->actionPtr(), task->argList());
    state->setCounterArgumentIndex(counterIndex);
    std::cout << "SET INCLUSIVE:" << isInclusive << std::endl;
    state->setIsInclusive(isInclusive);

    {
        auto f = std::bind(&ForAction::onResult, this, std::placeholders::_1);
        state->setResultCallback(f);
    }
    // TODO: error callback

    state->setCounter(counter);
    state->setUpTo(upTo);
    state->start();
}

void ForAction::emitComplete(const Value &reslutValue, const TaskId &taskId)
{
    // TODO: implement
    (void) reslutValue;
    (void) taskId;
}

void ForAction::onResult(const Result &result)
{
    notify(result);
    emitComplete(result.value(), result.taskId());
}

} // namespace cmd
} // namespace turnip
