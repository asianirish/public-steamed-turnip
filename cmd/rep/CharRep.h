#ifndef CHARREP_H
#define CHARREP_H

#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

class CharRep : public Representation
{
public:
    CharRep();

    Value input(const std::string &str) override;
    std::string output(const Value &value) override;

private:
    virtual char inputImpl(const std::string &str) = 0;
    virtual std::string outputImpl(char character) = 0;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // CHARREP_H
