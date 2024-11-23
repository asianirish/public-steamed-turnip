#ifndef MISSINGREQUIREDARGUMENTINFO_H
#define MISSINGREQUIREDARGUMENTINFO_H

#include "ArgumentInfo.h"

namespace turnip {
namespace cmd {
namespace err {

class MissingRequiredArgumentInfo : public ArgumentInfo
{
public:
    MissingRequiredArgumentInfo();

    MissingRequiredArgumentInfo(int argIndex, const std::string &argName = {});

    std::string description() const override;

};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // MISSINGREQUIREDARGUMENTINFO_H
