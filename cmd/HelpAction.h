#ifndef HELPACTION_H
#define HELPACTION_H

#include "Action.h"
#include "cmd/Menu.h"

namespace turnip {
namespace cmd {

class HelpAction : public Action
{
public:
    HelpAction();

    def::ActionDef actionDef() const;

    Menu *menu() const;
    void setMenu(Menu *newMenu);

private:
    Value actImpl(const ArgList &args, turnip::cmd::err::Error &error) override;

    Menu *menu_ {nullptr};
};

} // namespace cmd
} // namespace turnip

#endif // HELPACTION_H
