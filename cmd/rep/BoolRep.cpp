#include "BoolRep.h"

namespace turnip {
namespace cmd {
namespace rep {

const std::map<BoolRep::Kind, std::pair<std::string, std::string> > BoolRep::KIND_TO_STRING {
    {BoolRep::Kind::TrueFalse, {"true", "false"}},
    {BoolRep::Kind::OnOff, {"on", "of"}},
    {BoolRep::Kind::OneZero, {"1", "0"}},
    {BoolRep::Kind::YesNo, {"yes", "no"}}
};

BoolRep::BoolRep(Kind kind) : kind_(kind) {}

Value BoolRep::input(const std::string &str) const
{
    if (str == represent(true)) {
        return true;
    } else if (str == represent(false)) {
        return false;
    }

    return {};
}

std::string BoolRep::output(const Value &value) const
{
    bool yes = value;
    return represent(yes);
}

std::string BoolRep::represent(bool yes) const
{
    if (kind_ != Kind::Custom) {
        return yes ? KIND_TO_STRING.at(kind_).first : KIND_TO_STRING.at(kind_).second;
    }

    return yes ? customTrue_ : customFalse_;
}

std::string BoolRep::customTrue() const
{
    return customTrue_;
}

void BoolRep::setCustomTrue(const std::string &newCustomTrue)
{
    customTrue_ = newCustomTrue;
}

std::string BoolRep::customFalse() const
{
    return customFalse_;
}

void BoolRep::setCustomFalse(const std::string &newCustomFalse)
{
    customFalse_ = newCustomFalse;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
