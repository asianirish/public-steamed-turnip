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

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

private:
    Substitutor substitutor_;
};

} // namespace cmd
} // namespace turnip

#endif // COMPOSITEACTION_H
