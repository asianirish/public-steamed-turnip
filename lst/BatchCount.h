#ifndef BATCHCOUNT_H
#define BATCHCOUNT_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class BatchCount : public SyncAction
{
public:
    BatchCount();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // BATCHCOUNT_H
