#ifndef STATE_H
#define STATE_H

#include "cmd/TaskIdGenerator.h"
#include "cmd/TaskManager.h"
#include "cmd/Types.h"
#include "cmd/loop/StateManager.h"

namespace turnip {
namespace cmd {
namespace loop {

class State : public std::enable_shared_from_this<State>
{
public:

    // Define a type for the callback function
    using ResultCallback = std::function<void(const Result&)>;
    using ErrorCallback = std::function<void(const err::Error&)>;

    State(StateManager *manager, TaskId loopTaskId, const ActionPtr &action, const ArgList &args);

    void start();

    TaskId stateId() const;

    void setResultCallback(const ResultCallback &newResultCallback);

protected:
    virtual void handleResult(const Value resultValue) = 0; // Alters the state to influence the evaluation process.
    virtual void evaluate() = 0;
    virtual void modifyArgData(ArgList &newArgData) = 0;
    virtual void nextState() = 0;

    virtual Value accumulated() const = 0;

    void execute(const ActionPtr &action, ArgList args);

    void onEvaluationResult(bool success);

private:
    StateManager *manager_ {nullptr};
    StateId stateId_ {0};
    static std::shared_ptr<TaskIdGenerator> stateIdGen_;

    TaskId loopTaskId_ {0};

    TaskManager taskManager_;
    ActionPtr action_;
    ArgList argData_;

    // TODO: vector of?
    ResultCallback resultCallback_;
    ErrorCallback errorCallback_;

private:
    void onResult(const cmd::Result &result);
    void onError(const cmd::err::Error &error);

    void step();
};

} // namespace loop
} // namespace cmd
} // namespace turnip

#endif // STATE_H
