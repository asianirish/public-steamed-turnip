#include "TypeDef.h"
#include "cmd/rep/BoolRep.h"
#include "cmd/rep/RepresentationManager.h"

namespace turnip {
namespace cmd {
namespace def {

TypeDef::TypeDef() {}

std::string TypeDef::inputRep() const
{
    return inputRep_;
}

TypeDef::operator bool() const
{
    return !inputRep_.empty() && !outputRep_.empty();
}

TypeDef TypeDef::createNullTypedef(const NullRep &inputRep, const NullRep &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep.classKey();
    td.outputRep_ = outputRep.classKey();
    return td;
}

TypeDef TypeDef::createIntTypedef(const IntRep &inputRep, const IntRep &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep.classKey();
    td.outputRep_ = outputRep.classKey();
    return td;
}

TypeDef TypeDef::createDoubleTypedef(const DoubleRep &inputRep, const DoubleRep &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep.classKey();
    td.outputRep_ = outputRep.classKey();
    return td;
}

TypeDef TypeDef::createBoolTypedef()
{
    BoolRep boolRep;
    auto td = TypeDef();
    td.inputRep_ = boolRep.classKey();
    td.outputRep_ = boolRep.classKey();
    return td;
}

TypeDef TypeDef::createStringTypedef(const StringRep &inputRep, const StringRep &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep.classKey();
    td.outputRep_ = outputRep.classKey();
    return td;
}

TypeDef TypeDef::createCharTypedef(const CharRep &inputRep, const CharRep &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep.classKey();
    td.outputRep_ = outputRep.classKey();
    return td;
}

Value TypeDef::convertInput(const std::string &input) const
{
    auto inRep = rep::RepresentationManager::representation(inputRep_);

    if (inRep) {
        return inRep->input(input);
    }

    // TODO: else { copy error information to the returning value
    return Value();
}

} // namespace def
} // namespace cmd
} // namespace turnip
