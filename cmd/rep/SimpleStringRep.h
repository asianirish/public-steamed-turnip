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

    std::string repKey() const override {
        return "default";
    }
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // SIMPLESTRINGREP_H
