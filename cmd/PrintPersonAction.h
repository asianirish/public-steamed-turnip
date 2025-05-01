#ifndef PRINTPERSONACTION_H
#define PRINTPERSONACTION_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class PrintPersonAction : public SyncAction
{
public:
    PrintPersonAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // PRINTPERSONACTION_H
