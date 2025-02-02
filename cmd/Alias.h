#ifndef ALIAS_H
#define ALIAS_H

#include "cmd/Value.h"

#include <memory>

namespace turnip {
namespace cmd {

class Context;

class Alias
{
public:
    Alias(const std::shared_ptr<Context> &context, const std::string &key);

    std::string key() const;
    void setKey(const std::string &newKey);

    Value value() const;

    operator bool() const;

private:
    std::shared_ptr<Context> context_;
    std::string key_;
};

} // namespace cmd
} // namespace turnip

#endif // ALIAS_H
