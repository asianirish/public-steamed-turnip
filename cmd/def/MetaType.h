#ifndef METATYPE_H
#define METATYPE_H

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

private:
    Type type_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // METATYPE_H
