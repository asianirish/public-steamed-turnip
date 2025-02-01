#ifndef HUMANSTRINGGENERATOR_H
#define HUMANSTRINGGENERATOR_H

#include "StringGenerator.h"

namespace turnip {
namespace common {

class HumanStringGenerator : public StringGenerator
{
public:
    HumanStringGenerator();

    std::string generate() const final;
};

} // namespace common
} // namespace turnip

#endif // HUMANSTRINGGENERATOR_H
