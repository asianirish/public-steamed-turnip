#ifndef BOOLREP_H
#define BOOLREP_H

#include "Representation.h"


namespace turnip {
namespace cmd {
namespace rep {

class BoolRep : public Representation
{
public:
    enum class Kind {
        TrueFalse,
        OnOff,
        OneZero,
        YesNo,
        SuccessFailure,
        Custom
    };

    static const std::map<Kind, std::pair<std::string, std::string> > KIND_TO_STRING;

    BoolRep(Kind kind = Kind::TrueFalse);

    virtual Value input(const std::string &str) const override;
    virtual std::string output(const Value &value) const override;

    std::string represent(bool yes) const;

    std::string customTrue() const;
    void setCustomTrue(const std::string &newCustomTrue);

    std::string customFalse() const;
    void setCustomFalse(const std::string &newCustomFalse);

    std::string repKey() const override {
        if (kind_ == Kind::Custom) {
            return customTrue() + "/" + customFalse();
        }

        auto pr = KIND_TO_STRING.at(kind_);
        return pr.first + "/" + pr.second;
    }

    def::MetaType metaType() const override;
    Kind kind() const;
    void setKind(Kind newKind);

private:
    Kind kind_ {Kind::TrueFalse};

    std::string customTrue_;  // Used only if representation is Custom
    std::string customFalse_; // Used only if representation is Custom
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // BOOLREP_H
