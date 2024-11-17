#ifndef PRINTACTION_H
#define PRINTACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

class PrintAction : public Action
{
public:
    PrintAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args);
};

} // namespace cmd
} // namespace turnip

#endif // PRINTACTION_H
