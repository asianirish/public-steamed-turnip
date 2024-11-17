#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "cmd/Info.h"
#include <string>

namespace turnip {
namespace cmd {

class Translator
{
public:
    Translator();
    virtual ~Translator() = default;

    virtual Info translate(const std::string &in) const = 0;
};

} // namespace cmd
} // namespace turnip

#endif // TRANSLATOR_H
