#ifndef LISTTOARGSACTION_H
#define LISTTOARGSACTION_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace lst {

class ListToArgsAction : public SyncAction
{
public:
    ListToArgsAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // LISTTOARGSACTION_H
