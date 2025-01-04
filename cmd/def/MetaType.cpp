#include "MetaType.h"

namespace turnip {
namespace cmd {
namespace def {

MetaType::MetaType(Type type) : type_(type) {}

MetaType::Type MetaType::type() const
{
    return type_;
}

} // namespace def
} // namespace cmd
} // namespace turnip
