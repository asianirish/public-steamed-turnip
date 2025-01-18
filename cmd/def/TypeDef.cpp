#include "TypeDef.h"
#include "cmd/rep/BoolRep.h"

namespace turnip {
namespace cmd {
namespace def {

TypeDef::TypeDef() {}

RepPtr TypeDef::inputRep() const
{
    return inputRep_;
}

RepPtr TypeDef::outputRep() const
{
    return outputRep_ ? outputRep_ : inputRep_;
}

TypeDef::operator bool() const
{
    return !inputRep_ && !outputRep_;
}

TypeDef TypeDef::createNullTypedef(const Ptr<NullRep> &inputRep, const Ptr<NullRep> &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createIntTypedef(const Ptr<IntRep> &inputRep, const Ptr<IntRep> &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createDoubleTypedef(const Ptr<DoubleRep> &inputRep, const Ptr<DoubleRep> &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createBoolTypedef(BoolRep::Kind inputKind, BoolRep::Kind outputKind)
{
    auto td = TypeDef();
    td.inputRep_ = std::make_shared<BoolRep>(inputKind);
    td.outputRep_ = std::make_shared<BoolRep>(outputKind);
    return td;
}

TypeDef TypeDef::createStringTypedef(const Ptr<StringRep> &inputRep, const Ptr<StringRep> &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createCharTypedef(const Ptr<CharRep> &inputRep, const Ptr<CharRep> &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createTaskTypedef(const Ptr<TaskRep> &inputRep, const Ptr<TaskRep> &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

Value TypeDef::convertInput(const std::string &input) const
{
    if (inputRep_) {
        return inputRep_->input(input);
    }

    // TODO: else { copy error information to the returning value
    return Value();
}

std::string TypeDef::convertOutput(const Value &value) const
{
    if (outputRep()) {
        return outputRep()->output(value);
    }

    // TODO: else { copy error information to the returning value
    return {};
}

} // namespace def
} // namespace cmd
} // namespace turnip
