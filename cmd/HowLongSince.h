#ifndef HOWLONGSINCE_H
#define HOWLONGSINCE_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class HowLongSince : public SyncAction
{
public:
    HowLongSince();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // HOWLONGSINCE_H
