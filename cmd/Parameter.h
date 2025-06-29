#ifndef PARAMETER_H
#define PARAMETER_H

#include "cmd/Alias.h"
#include "cmd/Value.h"

namespace turnip {
namespace cmd {

class Substitutor;
using SubstPtr = std::shared_ptr<Substitutor>;

class Parameter
{
public:
    static const int INVALID_POSITION;
    Parameter();
    Parameter(int position);
    Parameter(const Value &value);

    Parameter(const ActionPtr &action);

    Parameter(const TaskPtr &task);

    Parameter(const SubstPtr &substPtr);

    Parameter(const ActionPtr &action, const ParamList &paramList);

    Parameter(const Alias &alias);

    Parameter(const Alias &alias, const ParamList &paramList);

    int position() const;
    void setPosition(int newPosition);
    bool isPosition() const;

    Value value() const;
    void setValue(const Value &newValue);

    SubstPtr substitutor() const;
    void setSubstitutor(const SubstPtr &newSubstitutor);

    VariantMap toMap() const;

    Alias alias() const;
    void setAlias(const Alias &newAlias);

private:
    int position_ {INVALID_POSITION};
    Value value_;
    std::shared_ptr<Alias> alias_;
    SubstPtr substitutor_;
};

} // namespace cmd
} // namespace turnip

#endif // PARAMETER_H
