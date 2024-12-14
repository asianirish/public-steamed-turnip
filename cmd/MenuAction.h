#ifndef MENUACTION_H
#define MENUACTION_H

#include "Action.h"
#include "cmd/Menu.h"

namespace turnip {
namespace cmd {

class MenuAction : public Action
{
public:
    MenuAction();

    def::ActionDef actionDef() const override;

    bool isAsync() const override {
        return false;
    }

    void setMenuName(const std::string &menuName);

    void addAction(const std::string &commandName, const Value &actionInfo);

private:
    Value actImpl(const ArgList &args, turnip::cmd::err::Error &error) override;

    Menu menu_;
};

} // namespace cmd
} // namespace turnip

#endif // MENUACTION_H
