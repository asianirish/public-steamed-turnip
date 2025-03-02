#ifndef ISEVEN_H
#define ISEVEN_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {
namespace math {

class IsEven : public turnip::cmd::SyncAction
{
public:
    IsEven();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // ISEVEN_H
