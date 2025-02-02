#include "Parameter.h"
#include "cmd/Substitutor.h"

#include <climits>

namespace turnip {
namespace cmd {

const int Parameter::INVALID_POSITION = INT_MIN;

Parameter::Parameter() : Parameter(Parameter::INVALID_POSITION) {}

Parameter::Parameter(int position) : position_(position)
{

}

Parameter::Parameter(const Value &value) : value_(value)
{

}

Parameter::Parameter(const ActionPtr &action) : value_(action)
{

}

Parameter::Parameter(const TaskPtr &task) : value_(task)
{

}

Parameter::Parameter(const SubstPtr &substPtr) : substitutor_(substPtr)
{

}

Parameter::Parameter(const ActionPtr &action, const ParamList &paramList)
{
    substitutor_ = mkPtr<Substitutor>(action, paramList);
}

Parameter::Parameter(const Alias &alias) : alias_(mkPtr<Alias>(alias))
{

}

Parameter::Parameter(const Alias &alias, const ParamList &paramList)
{
    substitutor_ = mkPtr<Substitutor>(alias, paramList);
}

int Parameter::position() const
{
    return position_;
}

void Parameter::setPosition(int newPosition)
{
    position_ = newPosition;
}

Value Parameter::value() const
{
    if (alias_) {
        return alias_->value();
    }

    return value_;
}

void Parameter::setValue(const Value &newValue)
{
    value_ = newValue;
}

SubstPtr Parameter::substitutor() const
{
    return substitutor_;
}

void Parameter::setSubstitutor(const SubstPtr &newSubstitutor)
{
    substitutor_ = newSubstitutor;
}

VariantMap Parameter::toMap() const
{
    VariantMap mp;
    if (position_ != INVALID_POSITION) {
        mp.set("position", position_);
    }

    if (alias_) {
        mp.set("alias", alias_->key());
    }

    if (!value_.isNull()) {
        mp.set("value", value_);
    }

    if (substitutor_) {
        mp.set("sub", substitutor_->toMap());
    }
    return mp;
}

Alias Parameter::alias() const
{
    return *alias_;
}

void Parameter::setAlias(const Alias &newAlias)
{
    alias_ = mkPtr<Alias>(newAlias);
}

} // namespace cmd
} // namespace turnip
