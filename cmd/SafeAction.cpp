#include "SafeAction.h"

namespace turnip {
namespace cmd {

SafeAction::SafeAction() {}

Value SafeAction::actImpl(const ArgList &args, err::Error &error)
{
    std::lock_guard lock(mutex());

    return actSafely(args, error);
}

} // namespace cmd
} // namespace turnip
