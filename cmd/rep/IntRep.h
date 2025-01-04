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

    Value input(const std::string &str) const override;
    std::string output(const Value &value) const override;

private:
    int64_t inputImpl(const std::string &str) const;
    virtual std::string outputImpl(int64_t number) const = 0;

    virtual int base() const = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // INTREP_H
