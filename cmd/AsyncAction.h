#ifndef ASYNCACTION_H
#define ASYNCACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

class AsyncAction : public Action
{
public:
    AsyncAction();

    void act(const TaskId &taskId, const ArgList &args) override;

    void onComplete(const Value &reslutValue, const TaskId &taskId);
    void onError(const err::Error &error);


private:
    virtual void emitRequest(const TaskId &taskId, const ArgList &args) = 0;
    virtual void emitComplete(const Value &reslutValue, const TaskId &taskId) = 0;
    // TODO: emitError(const err::Error &error);
};

} // namespace cmd
} // namespace turnip

#endif // ASYNCACTION_H
