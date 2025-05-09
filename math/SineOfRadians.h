#ifndef SINEOFRADIANS_H
#define SINEOFRADIANS_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace math {

class SineOfRadians : public turnip::cmd::SyncAction
{
public:
    SineOfRadians();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // SINEOFRADIANS_H
