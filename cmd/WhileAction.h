#ifndef WHILEACTION_H
#define WHILEACTION_H

#include "AsyncAction.h"
#include "cmd/loop/StateManager.h"

namespace turnip {
namespace cmd {

class WhileAction : public AsyncAction
{
public:
    WhileAction();

    def::ActionDef actionDef() const override;

private:
    void emitRequest(const TaskId &taskId, const ArgList &args) override;
    void emitComplete(const Value &reslutValue, const TaskId &taskId) override;

    void onResult(const cmd::Result &result);

private:
    loop::StateManager stateManager_;

    TaskPtr defaultTask_;
    TaskPtr defaultEvTask_;
};

} // namespace cmd
} // namespace turnip

#endif // WHILEACTION_H
