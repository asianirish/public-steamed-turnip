#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#include <string>

namespace turnip {
namespace common {

class StringGenerator
{
public:
    StringGenerator();

    virtual std::string generate() const = 0;
};

} // namespace common
} // namespace turnip

#endif // STRINGGENERATOR_H
