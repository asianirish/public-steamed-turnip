#ifndef SIZEACTION_H
#define SIZEACTION_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class SizeAction : public SyncAction
{
public:
    SizeAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // SIZEACTION_H
