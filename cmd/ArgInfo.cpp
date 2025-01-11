#include "ArgInfo.h"

namespace turnip {
namespace cmd {

ArgInfo::ArgInfo() : ArgInfo({}, {}) {}

ArgInfo::ArgInfo(const Value &value, const def::ArgDef &argDef) :
    value_(value),
    argDef_(argDef)
{

}

Value ArgInfo::value() const
{
    return value_;
}

void ArgInfo::setValue(const Value &newValue)
{
    value_ = newValue;
}

def::ArgDef ArgInfo::argDef() const
{
    return argDef_;
}

void ArgInfo::setArgDef(const def::ArgDef &newArgDef)
{
    argDef_ = newArgDef;
}

ArgInfo::operator Value() const
{
    if (!value_.isNull()) {
        return value_;
    }

    return argDef_.defaultValue();
}

} // namespace cmd
} // namespace turnip
