#ifndef BATCH_H
#define BATCH_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class Batch : public SyncAction
{
public:
    Batch();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // BATCH_H
