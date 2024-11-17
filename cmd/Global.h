#ifndef CMD_GLOBAL_H
#define CMD_GLOBAL_H

#include <string>
#include <vector>

namespace turnip {
namespace cmd {

// Function to split a string by a given delimiter
std::vector<std::string> splitString(const std::string& str, char delimiter);


} // namespace cmd
} // namespace turnip

#endif // CMD_GLOBAL_H
