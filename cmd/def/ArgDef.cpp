#include "ArgDef.h"

namespace turnip {
namespace cmd {
namespace def {

ArgDef::ArgDef() : type_(TypeDef::createNullTypedef()) {}

TypeDef ArgDef::type() const
{
    return type_;
}

void ArgDef::setType(const TypeDef &newType)
{
    type_ = newType;
}

std::string ArgDef::name() const
{
    return name_;
}

void ArgDef::setName(const std::string &newName)
{
    name_ = newName;
}

std::string ArgDef::desc() const
{
    return desc_;
}

void ArgDef::setDesc(const std::string &newDesc)
{
    desc_ = newDesc;
}

Value ArgDef::defaultValue() const
{
    return defaultValue_;
}

void ArgDef::setDefaultValue(const Value &newDefaultValue)
{
    defaultValue_ = newDefaultValue;
}

} // namespace def
} // namespace cmd
} // namespace turnip
