#include "MetaType.h"

namespace turnip {
namespace cmd {
namespace def {

std::map<MetaType::Type, std::string> MetaType::typeToName_ {
    {Invalid, "null"},
    {Bool, "bool"},
    {Char, "char"},
    {Int, "int"},
    {Double, "double"},
    {String, "string"},
    {Map, "map"},
    {List, "list"},
    {Task, "task"},
    {Action, "action"}
};

MetaType::MetaType(Type type) : type_(type) {}

std::string MetaType::name() const
{
    return typeToName_.at(type_);
}

MetaType::Type MetaType::type() const
{
    return type_;
}

} // namespace def
} // namespace cmd
} // namespace turnip
