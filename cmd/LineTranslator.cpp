#include "LineTranslator.h"
#include "cmd/Global.h"

namespace turnip {
namespace cmd {

LineTranslator::LineTranslator() {}

Info LineTranslator::translate(const std::string &in) const
{
    auto stringList = splitString(in, ' ');
    InputArgList args;
    args.reserve(stringList.size() - 1);

    auto it = stringList.cbegin();
    auto command = *it;
    ++it;

    // TODO: interpret the rest of stringList as a vector of Values (not strings)
    for (;it != stringList.end(); ++it) {
        args.push_back(*it);
    }

    Info info;
    info.setCommand(command);
    info.setArgs(args);
    return info;
}

} // namespace cmd
} // namespace turnip
