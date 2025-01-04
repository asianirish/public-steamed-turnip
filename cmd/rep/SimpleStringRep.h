#ifndef SIMPLESTRINGREP_H
#define SIMPLESTRINGREP_H

#include "StringRep.h"

namespace turnip {
namespace cmd {
namespace rep {

class SimpleStringRep : public StringRep
{
public:
    SimpleStringRep();

    std::string inputImpl(const std::string &str) const override;
    std::string outputImpl(const std::string &stringValue) const override;

    std::string classKey() const override {
        return "default_string";
    }
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // SIMPLESTRINGREP_H
