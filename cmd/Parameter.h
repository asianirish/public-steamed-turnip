#ifndef PARAMETER_H
#define PARAMETER_H

#include "cmd/Alias.h"
#include "cmd/Position.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {

class Substitutor;
using SubstPtr = std::shared_ptr<Substitutor>;

class Parameter
{
public:
    Parameter();
    Parameter(const Position &position);
    Parameter(const Value &value);

    Parameter(const ActionPtr &action);

    Parameter(const TaskPtr &task);

    Parameter(const SubstPtr &substPtr);

    Parameter(const ActionPtr &action, const ParamList &paramList);

    Parameter(const Alias &alias);

    Parameter(const Alias &alias, const ParamList &paramList);

    Position position() const;
    void setPosition(const Position &newPosition);
    bool isPosition() const;

    Value value() const;
    void setValue(const Value &newValue);

    SubstPtr substitutor() const;
    void setSubstitutor(const SubstPtr &newSubstitutor);

    VariantMap toMap() const;

    Alias alias() const;
    void setAlias(const Alias &newAlias);

private:
    Position position_;
    Value value_;
    std::shared_ptr<Alias> alias_;
    SubstPtr substitutor_;
};

} // namespace cmd
} // namespace turnip

#endif // PARAMETER_H
