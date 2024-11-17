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
    virtual int64_t inputImpl(const std::string &str) = 0;
    virtual std::string outputImpl(int64_t number) = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // INTREP_H
