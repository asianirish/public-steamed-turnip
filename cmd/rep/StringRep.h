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

    Value input(const std::string &str);
    std::string output(const Value &value);

private:
    virtual std::string inputImpl(const std::string &str) = 0;
    virtual std::string outputImpl(const std::string &stringValue) = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // STRINGREP_H
