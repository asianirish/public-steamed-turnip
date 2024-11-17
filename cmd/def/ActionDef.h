#ifndef ACTIONDEF_H
#define ACTIONDEF_H

#include "cmd/def/ArgDef.h"

#include <list>

namespace turnip {
namespace cmd {
namespace def {

class ActionDef
{
public:
    ActionDef();

    std::list<ArgDef> argDefs() const;
    void addArgDef(const ArgDef &argDef);
    ActionDef &operator <<(const ArgDef &argDef);

    std::string description() const;
    void setDescription(const std::string &newDescription);

private:
    std::list<ArgDef> argDefs_;
    std::string description_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // ACTIONDEF_H
