#ifndef DEGREESTORADIANS_H
#define DEGREESTORADIANS_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace math {

class DegreesToRadians : public turnip::cmd::SyncAction
{
public:
    DegreesToRadians();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // DEGREESTORADIANS_H
