#include "ActionDef.h"
#include "cmd/rep/RepresentationManager.h"

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

ActionDef::operator bool() const
{
    return !description_.empty();
}

void ActionDef::setResultRepresentation(const std::string &repKey)
{
    resultRepresentation_ = RepresentationManager::representation(repKey);
}

const Representation *ActionDef::resultRepresentation() const
{
    return resultRepresentation_;
}

} // namespace def
} // namespace cmd
} // namespace turnip
