#ifndef REPRESENTATIONMANAGER_H
#define REPRESENTATIONMANAGER_H

#include "cmd/rep/Representation.h"

#include <string>
#include <unordered_map>

namespace turnip {
namespace cmd {
namespace rep {

class RepresentationManager
{
public:
    RepresentationManager() = delete;

    // Registers a new representation with a given key
    static bool registerRepresentation(const std::string& key, std::unique_ptr<Representation> representation);

    // Retrieves a representation by key
    static Representation* representation(const std::string& key);

private:
    static std::unordered_map<std::string, std::unique_ptr<Representation>> representations_;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // REPRESENTATIONMANAGER_H
