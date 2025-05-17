#ifndef ASYNCPRINTACTION_H
#define ASYNCPRINTACTION_H

#include "AsyncAction.h"

namespace turnip {
namespace cmd {

class AsyncPrintAction : public AsyncAction
{
public:
    AsyncPrintAction();

public:
    def::ActionDef actionDef() const override;

private:
    void emitRequest(const TaskId &taskId, const ArgList &args) override;
    void emitComplete(const Value &reslutValue, const TaskId &taskId) override;

private:
    Ptr<Action> _printAction;
};

} // namespace cmd
} // namespace turnip

#endif // ASYNCPRINTACTION_H
