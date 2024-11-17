#include "ActionDef.h"

namespace turnip {
namespace cmd {
namespace def {

ActionDef::ActionDef() {}

std::list<ArgDef> ActionDef::argDefs() const
{
    return argDefs_;
}

void ActionDef::addArgDef(const ArgDef &argDef)
{
    argDefs_.push_back(argDef);
}

ActionDef &ActionDef::operator <<(const ArgDef &argDef)
{
    addArgDef(argDef);
    return *this;
}

std::string ActionDef::description() const
{
    return description_;
}

void ActionDef::setDescription(const std::string &newDescription)
{
    description_ = newDescription;
}

} // namespace def
} // namespace cmd
} // namespace turnip
