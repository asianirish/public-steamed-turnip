#ifndef COMMANDNOTFOUNDINFO_H
#define COMMANDNOTFOUNDINFO_H

#include "AdditionalInfo.h"

namespace turnip {
namespace cmd {
namespace err {

class CommandNotFoundInfo : public AdditionalInfo
{
public:
    CommandNotFoundInfo();

    CommandNotFoundInfo(const std::string &commandName);

    std::string description() const override;

private:
    std::string commandName_;

};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // COMMANDNOTFOUNDINFO_H
