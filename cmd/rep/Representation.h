#ifndef REPRESENTATION_H
#define REPRESENTATION_H

#include "cmd/Value.h"

namespace turnip {
namespace cmd {
namespace rep {

class Representation
{
public:
    Representation();

    virtual Value input(const std::string &str) const = 0;
    virtual std::string output(const Value &value) const = 0;

    virtual std::string classKey() const = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // REPRESENTATION_H
