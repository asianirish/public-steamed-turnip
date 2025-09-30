#include "Substitutor.h"
#include "cmd/Parameter.h"
#include "cmd/Task.h"

namespace turnip {
namespace cmd {

Substitutor::Substitutor() {}

Substitutor::Substitutor(const ActionPtr &action, const ParamList &paramList) :
    actionParam_(action),
    params_(paramList)
{

}

Substitutor::Substitutor(const Alias &alias, const ParamList &paramList) :
    actionParam_(alias),
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

TaskPtr Substitutor::substitute(const ArgList &args)
{
    if (actionParam_.isPosition()) {
        auto pos = actionParam_.position();
        auto arg = args.at(pos); // TODO: check if exists
        if (arg.isAction()) {
            actionParam_.setValue(arg);
        }
    }

    for (auto &param : params_) {
        if (param.isPosition()) {
            auto pos = param.position();

            if (pos.isValid() &&
                static_cast<size_t>(pos) < args.size()) {
                auto arg = args.at(pos);
                param.setValue(arg);
            }
        } else {
            auto sbst = param.substitutor();
            if (sbst) {
                auto subTask = sbst->substitute(args);
                param.setValue(subTask);
            }
        }
    }

    // TODO: clone action type to avoid circular references in case of recursive dependency

    TaskPtr taskPtr(new Task());

    ActionPtr actionPtr = actionParam_.value().toActionPtr();
    taskPtr->setActionPtr(actionPtr);

    ArgList argList;
    argList.reserve(params_.size());

    for (const auto &param : params_) {
        argList.push_back(param.value());
    }
    taskPtr->setArgList(argList);

    return taskPtr;
}

VariantMap Substitutor::toMap() const
{
    VariantMap mp;

    mp.set("actionParam", actionParam_.toMap());

    VariantList lst;
    lst.reserve(params_.size());

    for (const auto &param : params_) {
        lst.push_back(param.toMap());
    }
    mp.set("params", lst);

    return mp;
}


} // namespace cmd
} // namespace turnip
