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

Value ArgDef::convertInput(const std::string &input) const
{
    return type_.convertInput(input);
}

ArgDef::operator bool() const
{
    return static_cast<bool>(type_);
}

bool ArgDef::mustBeCalculated() const
{
    return mustBeCalculated_;
}

void ArgDef::setMustBeCalculated(bool newMustBeCalculated)
{
    mustBeCalculated_ = newMustBeCalculated;
}

VariantMap ArgDef::toMap() const
{
    VariantMap mp;

    if (!name_.empty()) {
        mp.set("name", name_);
    }

    if (!desc_.empty()) {
        mp.set("desc", desc_);
    }

    if (!defaultValue_.isNull()) {
        mp.set("defaultValue", defaultValue_);
    }

    mp.set("mustBeCalculated", mustBeCalculated_);

    auto input = type_.inputRep();
    if (input) {
        mp.set("input", input->toMap());
    }

    auto output = type_.outputRep();
    if (output && output != input) {
        mp.set("output", output->toMap());
    }

    return mp;
}

MetaType ArgDef::inputMetaType() const
{
    return type().inputMetaType();
}

MetaType ArgDef::outputMetaType() const
{
    return type().outputMetaType();
}

ConPtr ArgDef::constraint() const
{
    return constraint_;
}

void ArgDef::setConstraint(const ConPtr &newConstraint)
{
    constraint_ = newConstraint;
}

} // namespace def
} // namespace cmd
} // namespace turnip
