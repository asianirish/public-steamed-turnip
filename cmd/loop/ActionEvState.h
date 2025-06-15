#ifndef ACTIONEVSTATE_H
#define ACTIONEVSTATE_H

#include "State.h"

namespace turnip {
namespace cmd {
namespace loop {

class ActionEvState : public State
{
public:
    static const int INVALID_RESULT_INDEX = -1;

    ActionEvState(StateManager *manager, TaskId loopTaskId,
                  const ActionPtr &action, const ArgList &args,
                  const ActionPtr &evAction, const ArgList &evArgs);


    int resultEvArgumentIndex() const;
    void setResultEvArgumentIndex(int newResultEvArgumentIndex);

    int resultArgumentIndex() const;
    void setResultArgumentIndex(int newResultArgumentIndex);

protected:
    void handleResult(const Value resultValue) override;
    void evaluate() override;
    void modifyArgData(ArgList &newArgData) override;
    void nextState() override;

    Value accumulated() const override;

private:
    int resultEvArgumentIndex_ {INVALID_RESULT_INDEX};

    int resultArgumentIndex_ {INVALID_RESULT_INDEX};
    Value prevResultValue_;

    TaskManager evTaskManager_;
    ActionPtr evAction_;
    ArgList evArgData_;

private:
    void onEvaluationActionResult(const cmd::Result &result);
    void onEvaluationActionError(const cmd::err::Error &error);
};

} // namespace loop
} // namespace cmd
} // namespace turnip

#endif // ACTIONEVSTATE_H
