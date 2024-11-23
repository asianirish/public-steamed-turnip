#ifndef INTREP_H
#define INTREP_H

#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

class IntRep : public Representation
{
public:
    IntRep();

    Value input(const std::string &str) override;
    std::string output(const Value &value) override;

private:
    int64_t inputImpl(const std::string &str);
    virtual std::string outputImpl(int64_t number) = 0;

    virtual int base() const = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // INTREP_H
