#include "Info.h"

namespace turnip {
namespace cmd {

Info::Info() {}

std::string Info::command() const
{
    return command_;
}

void Info::setCommand(const std::string &newCommand)
{
    command_ = newCommand;
}

InputArgList Info::args() const
{
    return args_;
}

void Info::setArgs(const InputArgList &newArgs)
{
    args_ = newArgs;
}

} // namespace cmd
} // namespace turnip
