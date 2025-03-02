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

ActionDef::operator bool() const
{
    return !description_.empty();
}

RepPtr ActionDef::resultRepresentation() const
{
    return resultRepresentation_;
}

void ActionDef::setResultRepresentation(const RepPtr &newResultRepresentation)
{
    resultRepresentation_ = newResultRepresentation;
}

VariantMap ActionDef::toMap() const
{
    VariantMap mp;
    mp.set("desc", description_);

    if (resultRepresentation_) {
        mp.set("result", resultRepresentation_->toMap());
    }

    VariantList lst;

    for (const auto &argDef : argDefs_) {
        auto argDefMap = argDef.toMap();
        lst.push_back(argDefMap);
    }

    mp.set("argDefs", lst);

    return mp;
}


} // namespace def
} // namespace cmd
} // namespace turnip
