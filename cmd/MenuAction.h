#ifndef MENUACTION_H
#define MENUACTION_H

#include "SyncAction.h"
#include "cmd/Menu.h"

namespace turnip {
namespace cmd {

class MenuAction : public SyncAction
{
public:
    MenuAction();

    def::ActionDef actionDef() const override;

    bool doStartInThread() const override {
        return false;
    }

    void setMenuName(const std::string &menuName);

    void addAction(const std::string &commandName, const Value &actionInfo);

    void setTranslator(const std::shared_ptr<cmd::Translator> &newTrnsl);

private:
    Value actImpl(const ArgList &args, turnip::cmd::err::Error &error) override;

    Menu menu_;
};

} // namespace cmd
} // namespace turnip

#endif // MENUACTION_H
