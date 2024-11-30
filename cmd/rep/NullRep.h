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

    Value input(const std::string &str) override;
    std::string output(const Value &value) override;

    std::string nullString() const;
    void setNullString(const std::string &newNull_string);

    std::string classKey() const override {
        return "default_null";
    }

private:
    std::string nullString_ {"null"};

};


} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // NULLREP_H
