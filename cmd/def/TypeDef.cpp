#include "TypeDef.h"
#include "cmd/rep/RepresentationManager.h"

namespace turnip {
namespace cmd {
namespace def {

TypeDef::TypeDef() {}

TypeDef TypeDef::createNullTypedef(const std::string &inputRep, const std::string &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createIntTypedef(const std::string &inputRep, const std::string &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;

    return td;
}

TypeDef TypeDef::createStringTypedef(const std::string &inputRep, const std::string &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;

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
