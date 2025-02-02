#ifndef CONTEXT_H
#define CONTEXT_H

#include "cmd/Value.h"
#include "common/StringGenerator.h"

#include <map>
#include <string>

namespace turnip {
namespace cmd {

class Alias;

class Context : public std::enable_shared_from_this<Context>
{
public:
    static std::shared_ptr<Context> create();

    Value value(const std::string &key) const;
    Alias registerValue(const Value &value, const std::string &key = {});

    std::shared_ptr<common::StringGenerator> stringGen() const;
    void setStringGen(const std::shared_ptr<common::StringGenerator> &newStringGen);

    std::map<std::string, Value> values() const;

private:
    std::map<std::string, Value> values_;
    std::shared_ptr<common::StringGenerator> stringGen_;

    Context();
    std::shared_ptr<Context> sharedThis();
};

} // namespace cmd
} // namespace turnip

#endif // CONTEXT_H
