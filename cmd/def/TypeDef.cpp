#include "TypeDef.h"

namespace turnip {
namespace cmd {
namespace def {

std::map<size_t, TypeDef::TypeInfo> TypeDef::typeInfoMap {
    {0, {TypeDef::Id::Invalid, "Invalid"}},
    {1, {TypeDef::Id::Bool, "Bool"}},
    {2, {TypeDef::Id::Char, "Char"}},
    {3, {TypeDef::Id::Int, "Int"}},
    {4, {TypeDef::Id::String, "String"}},
    {5, {TypeDef::Id::Map, "Map"}}
};

TypeDef::TypeDef() : TypeDef(0) {}

TypeDef::TypeDef(std::size_t index) : index_(index)
{

}

TypeDef TypeDef::createNullTypedef(const std::string &inputRep, const std::string &outputRep)
{
    auto td = TypeDef();
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;
    return td;
}

TypeDef TypeDef::createIntTypedef(const std::string &inputRep, const std::string &outputRep)
{
    auto td = TypeDef(3);
    td.inputRep_ = inputRep;
    td.outputRep_ = outputRep;

    return td;
}

TypeDef::Id TypeDef::id() const
{
    return typeInfoMap.at(index_).id;
}

std::string TypeDef::name() const
{
    return typeInfoMap.at(index_).name;
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
