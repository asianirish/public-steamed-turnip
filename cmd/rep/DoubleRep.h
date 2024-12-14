#ifndef DOUBLEREP_H
#define DOUBLEREP_H

#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

class DoubleRep : public Representation
{
public:
    DoubleRep();

    Value input(const std::string &str) override;
    std::string output(const Value &value) override;

    std::string classKey() const override;
private:
    double inputImpl(const std::string &str);

    // Converts a double to a string in fixed precision format, avoiding scientific notation.
    // Can be overridden in derived classes for custom representation.
    virtual std::string outputImpl(double number);

    // Returns the default precision for double representation.
    // Can be overridden in derived classes for custom precision levels.
    virtual std::streamsize precision() const;

};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // DOUBLEREP_H
