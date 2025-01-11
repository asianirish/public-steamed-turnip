#ifndef ARGINFO_H
#define ARGINFO_H

#include "cmd/Value.h"
#include "cmd/def/ArgDef.h"

namespace turnip {
namespace cmd {

class ArgInfo
{
public:
    ArgInfo();
    ArgInfo(const Value &value, const def::ArgDef &argDef);

    Value value() const;
    void setValue(const Value &newValue);

    def::ArgDef argDef() const;
    void setArgDef(const def::ArgDef &newArgDef);

    operator Value() const;

private:
    Value value_;
    def::ArgDef argDef_;
};

} // namespace cmd
} // namespace turnip

#endif // ARGINFO_H
