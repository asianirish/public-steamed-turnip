#ifndef DECINTREP_H
#define DECINTREP_H

#include "IntRep.h"

namespace turnip {
namespace cmd {
namespace rep {

class DecIntRep : public IntRep
{
public:
    DecIntRep();

    std::string classKey() const override {
        return "default_int";
    }

private:
    // Converts an int64_t to its string representation
    std::string outputImpl(int64_t number) override;

    int base() const override {
        return 10;
    }
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // DECINTREP_H
