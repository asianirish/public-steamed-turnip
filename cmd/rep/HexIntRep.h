#ifndef HEXINTREP_H
#define HEXINTREP_H

#include "IntRep.h"

namespace turnip {
namespace cmd {
namespace rep {

class HexIntRep : public IntRep
{
public:
    HexIntRep();

    std::string repKey() const override {
        return "hex";
    }
private:
    // Converts an int64_t to its hexadecimal string representation
    std::string outputImpl(int64_t number) const override;

    int base() const override {
        return 16;
    }
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // HEXINTREP_H
