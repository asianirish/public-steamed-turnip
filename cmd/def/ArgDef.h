#ifndef ARGDEF_H
#define ARGDEF_H

#include "cmd/Value.h"
#include "cmd/def/TypeDef.h"

namespace turnip {
namespace cmd {
namespace def {

class ArgDef
{
public:
    ArgDef();

    TypeDef type() const;
    void setType(const TypeDef &newType);

    std::string name() const;
    void setName(const std::string &newName);

    std::string desc() const;
    void setDesc(const std::string &newDesc);

    Value defaultValue() const;
    void setDefaultValue(const Value &newDefaultValue);

    Value convertInput(const std::string &input) const;

    operator bool() const;

    bool mustBeCalculated() const;
    void setMustBeCalculated(bool newMustBeCalculated);

    VariantMap toMap() const;

    MetaType inputMetaType() const;
    MetaType outputMetaType() const;

private:
    TypeDef type_;
    std::string name_;
    std::string desc_;

    Value defaultValue_;

    bool mustBeCalculated_ {true};
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // ARGDEF_H
