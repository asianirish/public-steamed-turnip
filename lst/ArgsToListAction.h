#ifndef ARGSTOLISTACTION_H
#define ARGSTOLISTACTION_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class ArgsToListAction : public SyncAction
{
public:
    ArgsToListAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // ARGSTOLISTACTION_H
