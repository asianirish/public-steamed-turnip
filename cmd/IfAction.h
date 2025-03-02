#ifndef IFACTION_H
#define IFACTION_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class IfAction : public SyncAction
{
public:
    IfAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // IFACTION_H
