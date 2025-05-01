#ifndef MAPTOARGSACTION_H
#define MAPTOARGSACTION_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class MapToArgsAction : public SyncAction
{
public:
    MapToArgsAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // MAPTOARGSACTION_H
