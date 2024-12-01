#ifndef HELPACTION_H
#define HELPACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

class HelpAction : public Action
{
public:
    HelpAction();

    def::ActionDef actionDef() const;

private:
    Value actImpl(const ArgList &args);
};

} // namespace cmd
} // namespace turnip

#endif // HELPACTION_H
