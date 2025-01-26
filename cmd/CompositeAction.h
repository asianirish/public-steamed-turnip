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
    void setSubstitutor(const Substitutor &newSubstitutor);

    def::ActionDef actionDef() const override;
    void setActionDef(const def::ActionDef &newActionDef);

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
