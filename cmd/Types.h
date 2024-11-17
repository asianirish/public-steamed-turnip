#ifndef CMD_TYPES_H
#define CMD_TYPES_H

#include "cmd/Value.h"

#include <vector>

namespace turnip {
namespace cmd {

using ArgList = std::vector<Value>;

using InputArgList = std::vector<std::string>;


class Action;
using ActionPtr = std::shared_ptr<Action>;

} // namespace cmd
} // namespace turnip

#endif // CMD_TYPES_H
