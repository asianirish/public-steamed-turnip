#ifndef COUNTINGACTION_H
#define COUNTINGACTION_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class CountingAction : public SyncAction
{
public:
    CountingAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // COUNTINGACTION_H
