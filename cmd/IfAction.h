#ifndef IFACTION_H
#define IFACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

class IfAction : public Action
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
