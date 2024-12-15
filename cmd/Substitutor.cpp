#include "Substitutor.h"
#include "cmd/Parameter.h"

namespace turnip {
namespace cmd {

Substitutor::Substitutor() {}

Parameter Substitutor::actionParam() const
{
    return actionParam_;
}

void Substitutor::setActionParam(const Parameter &newActionParam)
{
    actionParam_ = newActionParam;
}

ParamList Substitutor::params() const
{
    return params_;
}

TaskPtr Substitutor::substitue(const ArgList &args)
{
    (void)args;
    // TODO: implement
    // TODO: clone action type to avoid circular references in case of recursive dependency
    // TODO: (or use weak pointers)
    return {};
}


} // namespace cmd
} // namespace turnip
