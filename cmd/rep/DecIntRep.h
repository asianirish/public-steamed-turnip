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

private:
    // Converts a string representation of a decimal integer to an int64_t
    int64_t inputImpl(const std::string &str);

    // Converts an int64_t to its string representation
    std::string outputImpl(int64_t number);
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // DECINTREP_H
