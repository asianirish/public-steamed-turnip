#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

Representation::Representation() {}

std::string Representation::info() const
{
    return metaType().name() + "-" + repKey();
}

std::string Representation::registeredClassName() const
{
    if (registeredClassName_) {
        return *registeredClassName_;
    }

    return {};
}

void Representation::setRegisteredClassName(const std::string *newRegisteredClassName)
{
    registeredClassName_ = newRegisteredClassName;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
