#ifndef ASYNCCOMPOSITEACTION_H
#define ASYNCCOMPOSITEACTION_H

#include "AsyncAction.h"
#include "cmd/Substitutor.h"

namespace turnip {
namespace cmd {

class AsyncCompositeAction : public AsyncAction
{
public:
    AsyncCompositeAction();

    def::ActionDef actionDef() const override;
    void setActionDef(const def::ActionDef &newActionDef);

    Substitutor substitutor() const;

    void onSubTaskComplete(const Value &reslutValue, const TaskId &taskId);

    void setAction(const ActionPtr &action);
    void setAction(const Alias &alias);

    void addParam(int position);
    void addParam(const Value &value);
    void addParam(const ActionPtr &action);
    void addParam(const ActionPtr &action, const ParamList &paramList);

    void addParam(const Alias &alias, const ParamList &paramList);

    void addParams(const ParamList &paramList);

private:
    void emitRequest(const TaskId &taskId, const ArgList &args) override;
    void emitComplete(const Value &reslutValue, const TaskId &taskId) override;

private:
    Substitutor substitutor_;
    def::ActionDef actionDef_;
};

} // namespace cmd
} // namespace turnip

#endif // ASYNCCOMPOSITEACTION_H
