#ifndef COMPOSITEACTION_H
#define COMPOSITEACTION_H

#include "Action.h"
#include "cmd/Substitutor.h"

namespace turnip {
namespace cmd {

class CompositeAction : public Action
{
public:
    CompositeAction();

    Substitutor substitutor() const;

    def::ActionDef actionDef() const override;
    void setActionDef(const def::ActionDef &newActionDef);

    void setAction(const ActionPtr &action);
    void addParam(int position);
    void addParam(const Value &value);
    void addParam(const ActionPtr &action);
    void addParam(const ActionPtr &action, const ParamList &paramList);
    // TODO: use action param for action

    void addParams(const ParamList &paramList);

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

    VariantMap data() const override;

private:
    Substitutor substitutor_;
    def::ActionDef actionDef_;
};

} // namespace cmd
} // namespace turnip

#endif // COMPOSITEACTION_H
