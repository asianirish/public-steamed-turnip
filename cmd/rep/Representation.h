#ifndef REPRESENTATION_H
#define REPRESENTATION_H

#include "cmd/Value.h"
#include "cmd/def/MetaType.h"

namespace turnip {
namespace cmd {
namespace rep {

class Representation
{
public:
    Representation();

    virtual Value input(const std::string &str) const = 0;
    virtual std::string output(const Value &value) const = 0;

    virtual std::string repKey() const = 0;

    virtual def::MetaType metaType() const = 0;

    std::string info() const;

    std::string registeredClassName() const;
    void setRegisteredClassName(const std::string *newRegisteredClassName);

    // should not be used directly
    static std::string checkClassName(const std::string &className) {
        return className;
    }

private:
    const std::string *registeredClassName_ = nullptr;
};

#define REPRESENTATION_CLASS(className) className::checkClassName(#className)

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // REPRESENTATION_H
