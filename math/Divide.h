#ifndef DIVIDE_H
#define DIVIDE_H

#include "cmd/Action.h"

namespace turnip {
namespace cmd {
namespace math {

class Divide : public turnip::cmd::Action
{
public:
    Divide();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace math
} // namespace cmd
} // namespace turnip

#endif // DIVIDE_H
