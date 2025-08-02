#ifndef BATCHNUMBER_H
#define BATCHNUMBER_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class BatchNumber : public SyncAction
{
public:
    BatchNumber();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // BATCHNUMBER_H
