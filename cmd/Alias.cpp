#include "Alias.h"

#include "cmd/Context.h"

namespace turnip {
namespace cmd {

Alias::Alias(const std::shared_ptr<Context> &context, const std::string &key) : context_(context),
    key_(key) {}

std::string Alias::key() const
{
    return key_;
}

void Alias::setKey(const std::string &newKey)
{
    key_ = newKey;
}

Value Alias::value() const
{
    if (key_.empty()) {
        return {};
    }

    return context_->value(key_);
}

Alias::operator bool() const
{
    if (key_.empty()) {
        return false;
    }

    return !value().isNull();
}

} // namespace cmd
} // namespace turnip
