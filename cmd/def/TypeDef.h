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
    static TypeDef createNullTypedef(const std::string &inputRep = App::DEFAULT_NULL_REPRESENTATION,
                                     const std::string &outputRep = App::DEFAULT_NULL_REPRESENTATION);

    static TypeDef createIntTypedef(const std::string & inputRep = App::DEFAULT_INT_REPRESENTATION,
                                    const std::string &outputRep = App::DEFAULT_INT_REPRESENTATION);

    static TypeDef createStringTypedef(const std::string & inputRep = App::DEFAULT_STRING_REPRESENTATION,
                                    const std::string &outputRep = App::DEFAULT_STRING_REPRESENTATION);

    Value convertInput(const std::string &input) const;

private:
    TypeDef();

private:
    std::string inputRep_;
    std::string outputRep_;
};

} // namespace def
} // namespace cmd
} // namespace turnip

#endif // TYPEDEF_H
