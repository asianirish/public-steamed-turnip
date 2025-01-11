#include "Substitutor.h"
#include "cmd/Parameter.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

Substitutor::Substitutor() {}

Substitutor::Substitutor(const LazyAction &action, const ParamList &paramList) :
    actionParam_(action),
    params_(paramList)
{

}

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

void Substitutor::addParam(const Parameter &param)
{
    params_.push_back(param);
}

TaskPtr Substitutor::substitue(const ArgList &args)
{
    // TODO: substitue actionParam_ as well

    int i = 0;
    for (auto arg : args) {
        for (auto &param : params_) {
            if (param.position() == i) {
                param.setValue(arg);
            } else {
                auto sbst = param.substitutor();
                if (sbst) {
                    auto subTask = sbst->substitue(args);
                    param.setValue(subTask);
                }
            }
        }
        ++i;
    }

    // TODO: clone action type to avoid circular references in case of recursive dependency

    TaskPtr taskPtr(new Task());

    ActionPtr actionPtr = actionParam_.value().toActionPtr();
    taskPtr->setActionPtr(actionPtr);

    ArgList argList;

    for (auto param : params_) {
        argList.push_back(param.value());
    }
    taskPtr->setArgList(argList);

    return taskPtr;
}


} // namespace cmd
} // namespace turnip
