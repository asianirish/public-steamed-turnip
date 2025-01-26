#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

const std::string Representation::CLASS_NAME_KEY {"repClass"};

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

VariantMap Representation::toMap() const
{
    VariantMap mp;
    if (registeredClassName_) {
        mp.set(CLASS_NAME_KEY, *registeredClassName_);
    } else {
        mp.set("type", metaType().name());
        mp.set("representation", repKey());
    }

    // TODO:
    // if (!data().empty()) {
    //     mp.set(DATA_KEY, data());
    // }

    return mp;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
