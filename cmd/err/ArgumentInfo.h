#ifndef ARGUMENTINFO_H
#define ARGUMENTINFO_H

#include "AdditionalInfo.h"

namespace turnip {
namespace cmd {
namespace err {

class ArgumentInfo : public AdditionalInfo
{
public:
    ArgumentInfo();

    ArgumentInfo(int argIndex, const std::string &argName = {});

    int argIndex() const;
    void setArgIndex(int newArgIndex);

    std::string argName() const;
    void setArgName(const std::string &newArgName);

private:
    int argIndex_ {-1};
    std::string argName_;
};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // ARGUMENTINFO_H
