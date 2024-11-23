#ifndef ADDITIONALINFO_H
#define ADDITIONALINFO_H

#include <string>

namespace turnip {
namespace cmd {
namespace err {

class AdditionalInfo
{
public:
    AdditionalInfo();
    virtual ~AdditionalInfo() = default;

    virtual std::string description() const = 0;
};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // ADDITIONALINFO_H
