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

    std::string repKey() const override {
        return "symbol";
    }

private:
    char inputImpl(const std::string &str) const override;
    std::string outputImpl(char character) const override;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // SIMPLECHARREP_H
