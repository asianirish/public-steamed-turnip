#include "Global.h"


namespace turnip {
namespace cmd {

std::vector<std::string> splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    size_t start = 0; // Start position for finding substrings
    size_t end = str.find(delimiter); // Find first occurrence of the delimiter

    while (end != std::string::npos) {
        // Extract substring and add it to the tokens vector
        tokens.push_back(str.substr(start, end - start));
        start = end + 1; // Move start to the character after the delimiter
        end = str.find(delimiter, start); // Find the next occurrence of the delimiter
    }

    // Add the last token to the vector
    tokens.push_back(str.substr(start));

    return tokens;
}


} // namespace cmd
} // namespace turnip
