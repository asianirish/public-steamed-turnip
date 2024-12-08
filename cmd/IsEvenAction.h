#ifndef ISEVENACTION_H
#define ISEVENACTION_H

#include "cmd/Action.h"

namespace turnip {
namespace cmd {
namespace math {

class IsEvenAction : public turnip::cmd::Action
{
public:
    IsEvenAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // ISEVENACTION_H
