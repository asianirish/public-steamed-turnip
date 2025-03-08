#ifndef SYNCACTION_H
#define SYNCACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {


class SyncAction : public Action
{
public:
    SyncAction();

    void act(const TaskId &taskId, const ArgList &args) override;

    bool doStartInThread() const override {
        return true;
    }

private:
    virtual Value actImpl(const ArgList &args, err::Error &error) = 0;

};


} // namespace cmd
} // namespace turnip

#endif // SYNCACTION_H
