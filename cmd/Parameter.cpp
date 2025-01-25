#include "Parameter.h"
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

Parameter::Parameter(const SubstPtr &substPtr) : substitutor_(substPtr)
{

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

} // namespace cmd
} // namespace turnip
