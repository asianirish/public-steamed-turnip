#ifndef METATYPE_H
#define METATYPE_H

#include <map>
#include <string>

namespace turnip {
namespace cmd {
namespace def {

class MetaType
{
public:
    enum Type {
        Invalid,
        Bool,
        Char,
        Int,
        Double,
        String,
        Map,
        List,
        Task,
        Action,
    };

    MetaType(Type type = Invalid);

    Type type() const;

    std::string name() const;

private:
    Type type_;

    static std::map<Type, std::string> typeToName_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // METATYPE_H
