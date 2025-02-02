#include "Context.h"
#include "cmd/Alias.h"

namespace turnip {
namespace cmd {

Context::Context() {}

std::shared_ptr<Context> Context::create()
{
    return std::shared_ptr<Context>(new Context());
}

Value Context::value(const std::string &key) const
{
#if __cplusplus >= 202002L
    if (!values_.contains(key)) {
#else
    if (values_.find(key) == values_.end()) {
#endif
        return {}; // return a null value
    }

    return values_.at(key);
}

Alias Context::registerValue(const Value &value, const std::string &key)
{
    std::string keyString;

    if (key.empty()) {
        keyString = stringGen_->generate();
    } else {
        keyString = key;
    }
#if __cplusplus >= 202002L
    if (values_.contains(keyString)) {
#else
    if (values_.find(keyString) != values_.end()) {
#endif
        return registerValue(value); // register with a unique key
    }

    values_.insert({keyString, value});

    return Alias(sharedThis(), keyString);
}

std::shared_ptr<common::StringGenerator> Context::stringGen() const
{
    return stringGen_;
}

void Context::setStringGen(const std::shared_ptr<common::StringGenerator> &newStringGen)
{
    stringGen_ = newStringGen;
}

std::map<std::string, Value> Context::values() const
{
    return values_;
}

std::shared_ptr<Context> Context::sharedThis()
{
    return shared_from_this();
}

} // namespace cmd
} // namespace turnip
