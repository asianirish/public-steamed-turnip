#ifndef SIMPLECHARREP_H
#define SIMPLECHARREP_H

#include "CharRep.h"

namespace turnip {
namespace cmd {
namespace rep {

class SimpleCharRep : public CharRep
{
public:
    SimpleCharRep();

    std::string classKey() const override {
        return "default_char";
    }

private:
    char inputImpl(const std::string &str) const override;
    std::string outputImpl(char character) const override;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // SIMPLECHARREP_H
