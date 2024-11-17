#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "cmd/rep/IntRep.h"
#include "cmd/rep/NullRep.h"
#include "App.h"

#include <cstddef>
#include <map>
#include <string>

namespace turnip {
namespace cmd {
namespace def {

using namespace rep;

class TypeDef
{
public:
    // in the order of the type arguments specified for Value::data_, as they appear in the sequence of the template arguments
    enum class Id {
        Invalid,
        Bool,
        Char,
        Int,
        String,
        Map,
    };

    static TypeDef createNullTypedef(const std::string &inputRep = App::DEFAULT_NULL_REPRESENTATION,
                                     const std::string &outputRep = App::DEFAULT_NULL_REPRESENTATION);

    static TypeDef createIntTypedef(const std::string & inputRep = App::DEFAULT_INT_REPRESENTATION,
                                    const std::string &output_Rep = App::DEFAULT_INT_REPRESENTATION);

    Id id() const;

    std::string name() const;

private:
    TypeDef();

    TypeDef(std::size_t index);

private:
    std::size_t index_;

    struct TypeInfo{
        Id id;
        std::string name;
    };

    static std::map<size_t, TypeInfo> typeInfoMap;

    std::string inputRep_;
    std::string outputRep_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // TYPEDEF_H
