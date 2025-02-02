#ifndef COUNTINGACTION_H
#define COUNTINGACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

class CountingAction : public Action
{
public:
    CountingAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // COUNTINGACTION_H
