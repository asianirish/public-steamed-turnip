#ifndef CONDITIONALSTRINGACTION_H
#define CONDITIONALSTRINGACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

class ConditionalStringAction : public Action
{
public:
    ConditionalStringAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // CONDITIONALSTRINGACTION_H
