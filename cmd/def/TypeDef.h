#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "cmd/rep/DecIntRep.h"
#include "cmd/rep/NullRep.h"
#include "cmd/rep/SimpleStringRep.h"

#include <string>

namespace turnip {
namespace cmd {
namespace def {

using namespace rep;

class TypeDef
{
public:
    static TypeDef createNullTypedef(const NullRep &inputRep = {}, const NullRep &outputRep = {});

    static TypeDef createIntTypedef(const IntRep &inputRep = DecIntRep(), const IntRep &outputRep = DecIntRep());

    static TypeDef createBoolTypedef();

    static TypeDef createStringTypedef(const StringRep &inputRep = SimpleStringRep(), const StringRep &outputRep = SimpleStringRep());

    Value convertInput(const std::string &input) const;

    std::string inputRep() const;

    operator bool() const;

private:
    TypeDef();

private:
    std::string inputRep_;
    std::string outputRep_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // TYPEDEF_H
