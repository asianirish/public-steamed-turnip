#ifndef INFO_H
#define INFO_H

#include "cmd/Types.h"


namespace turnip {
namespace cmd {

class Info
{
public:
    Info();

    std::string command() const;
    void setCommand(const std::string &newCommand);

    InputArgList args() const;
    void setArgs(const InputArgList &newArgs);

private:
    std::string command_;
    InputArgList args_;
};

} // namespace cmd
} // namespace turnip

#endif // INFO_H
