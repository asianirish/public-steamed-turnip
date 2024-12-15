#include "CompositeAction.h"

namespace turnip {
namespace cmd {

CompositeAction::CompositeAction() {}

Substitutor CompositeAction::substitutor() const
{
    return substitutor_;
}

void CompositeAction::setSubstitutor(const Substitutor &newSubstitutor)
{
    substitutor_ = newSubstitutor;
}

Value CompositeAction::actImpl(const ArgList &args, err::Error &error)
{
    auto task = substitutor_.substitue(args);
    // TODO: use error
    (void)error;
    return task;
}

def::ActionDef CompositeAction::actionDef() const
{
    return actionDef_;
}

void CompositeAction::setActionDef(const def::ActionDef &newActionDef)
{
    actionDef_ = newActionDef;
}

} // namespace cmd
} // namespace turnip
