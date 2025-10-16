#include "CompositeAction.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

CompositeAction::CompositeAction() {}

Substitutor CompositeAction::substitutor() const
{
    return substitutor_;
}

Value CompositeAction::actImpl(const ArgList &args, err::Error &error)
{
    auto task = substitutor_.substitute(args);

#ifdef DEBUG_ACTION_TASKS
    std::cout << std::endl << "INNER TASK:" << task->taskId() << std::endl;
    std::cout << "THIS TASK:" << error.maybeTaskId().value() << std::endl;
#else
    // TODO: use error
    (void)error;
#endif

    return task;
}

VariantMap CompositeAction::data() const
{
    VariantMap mp;

    mp.set("def", actionDef_.toMap());
    mp.set("substitutor", substitutor_.toMap());

    return mp;
}

def::ActionDef CompositeAction::actionDef() const
{
    return actionDef_;
}

void CompositeAction::setActionDef(const def::ActionDef &newActionDef)
{
    actionDef_ = newActionDef;
}

void CompositeAction::setAction(const ActionPtr &action)
{
    substitutor_.setActionParam(action);
}

void CompositeAction::setAction(const Alias &alias)
{
    substitutor_.setActionParam(alias);
}

void CompositeAction::addParam(const Position &position)
{
    substitutor_.addParam(Parameter(position));
}

void CompositeAction::addParam(const Value &value)
{
    substitutor_.addParam(Parameter(value));
}

void CompositeAction::addParam(const ActionPtr &action)
{
    substitutor_.addParam(Parameter(action));
}

void CompositeAction::addParam(const ActionPtr &action, const ParamList &paramList)
{
    substitutor_.addParam(Parameter(action, paramList));
}

void CompositeAction::addParam(const Alias &alias, const ParamList &paramList)
{
    substitutor_.addParam(Parameter(alias, paramList));
}

void CompositeAction::addParams(const ParamList &paramList)
{
    for (const auto &param : paramList) {
        substitutor_.addParam(param);
    }
}

} // namespace cmd
} // namespace turnip
