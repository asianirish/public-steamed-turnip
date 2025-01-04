#ifndef STRINGREP_H
#define STRINGREP_H

#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

class StringRep : public Representation
{
public:
    StringRep();

    Value input(const std::string &str) const override;
    std::string output(const Value &value) const override;
private:
    virtual std::string inputImpl(const std::string &str) const = 0;
    virtual std::string outputImpl(const std::string &stringValue) const = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // STRINGREP_H
