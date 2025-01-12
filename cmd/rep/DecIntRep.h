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

    std::string repKey() const override {
        return "dec";
    }

private:
    // Converts an int64_t to its string representation
    std::string outputImpl(int64_t number) const override;

    int base() const override {
        return 10;
    }
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // DECINTREP_H
