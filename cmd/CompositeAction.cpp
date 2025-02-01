#include "CompositeAction.h"

namespace turnip {
namespace cmd {

CompositeAction::CompositeAction() {}

Substitutor CompositeAction::substitutor() const
{
    return substitutor_;
}

Value CompositeAction::actImpl(const ArgList &args, err::Error &error)
{
    auto task = substitutor_.substitue(args);
    // TODO: use error
    (void)error;
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

void CompositeAction::addParam(int position)
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

void CompositeAction::addParams(const ParamList &paramList)
{
    for (auto &param : paramList) {
        substitutor_.addParam(param);
    }
}

} // namespace cmd
} // namespace turnip
