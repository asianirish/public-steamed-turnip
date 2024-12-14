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

    def::ActionDef actionDef() const override;

    Menu *menu() const;
    void setMenu(Menu *newMenu);

    virtual bool isAsync() const override {
        return false;
    }

private:
    Value actImpl(const ArgList &args, turnip::cmd::err::Error &error) override;

    Menu *menu_ {nullptr};
};

} // namespace cmd
} // namespace turnip

#endif // HELPACTION_H
