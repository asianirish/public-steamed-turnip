#ifndef CONCATLISTACTION_H
#define CONCATLISTACTION_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class ConcatListAction : public SyncAction
{
public:
    ConcatListAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // CONCATLISTACTION_H
