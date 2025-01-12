#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "cmd/rep/DecIntRep.h"
#include "cmd/rep/DoubleRep.h"
#include "cmd/rep/NullRep.h"
#include "cmd/rep/SimpleStringRep.h"
#include "cmd/rep/SimpleCharRep.h"
#include "cmd/rep/BoolRep.h"

#include <string>

namespace turnip {
namespace cmd {
namespace def {

using namespace rep;

class TypeDef
{
public:
    static TypeDef createNullTypedef(const Ptr<NullRep> &inputRep = {}, const Ptr<NullRep> &outputRep = {});

    static TypeDef createIntTypedef(const Ptr<IntRep> &inputRep = mkPtr<DecIntRep>(), const Ptr<IntRep> &outputRep = mkPtr<DecIntRep>());

    static TypeDef createDoubleTypedef(const Ptr<DoubleRep> &inputRep = mkPtr<DoubleRep>(), const Ptr<DoubleRep> &outputRep = mkPtr<DoubleRep>());

    static TypeDef createBoolTypedef(BoolRep::Kind inputKind = BoolRep::Kind::TrueFalse, BoolRep::Kind outputKind = BoolRep::Kind::TrueFalse);

    static TypeDef createStringTypedef(const Ptr<StringRep> &inputRep = mkPtr<SimpleStringRep>(), const Ptr<StringRep> &outputRep = mkPtr<SimpleStringRep>());

    static TypeDef createCharTypedef(const Ptr<CharRep> &inputRep = mkPtr<SimpleCharRep>(), const Ptr<CharRep> &outputRep = mkPtr<SimpleCharRep>());

    Value convertInput(const std::string &input) const;

    RepPtr inputRep() const;

    operator bool() const;

private:
    TypeDef();

private:
    RepPtr inputRep_;
    RepPtr outputRep_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // TYPEDEF_H
