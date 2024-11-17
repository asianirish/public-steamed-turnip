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

private:
    // Converts a string representation of a hexadecimal integer to an int64_t
    int64_t inputImpl(const std::string &str) override;

    // Converts an int64_t to its hexadecimal string representation
    std::string outputImpl(int64_t number) override;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // HEXINTREP_H
