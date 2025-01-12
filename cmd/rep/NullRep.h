#ifndef NULLREP_H
#define NULLREP_H

#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

class NullRep : public Representation
{
public:
    NullRep();

    Value input(const std::string &str) const override;
    std::string output(const Value &value) const override;

    std::string nullString() const;
    void setNullString(const std::string &newNull_string);

    std::string repKey() const override {
        return "default";
    }

    def::MetaType metaType() const override;

private:
    std::string nullString_ {"null"};

};


} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // NULLREP_H
