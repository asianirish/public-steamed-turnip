#ifndef ATACTION_H
#define ATACTION_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class AtAction : public SyncAction
{
public:
    AtAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // ATACTION_H
