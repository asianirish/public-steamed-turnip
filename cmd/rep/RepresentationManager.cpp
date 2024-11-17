#include "RepresentationManager.h"

namespace turnip {
namespace cmd {
namespace rep {

std::unordered_map<std::string, std::unique_ptr<Representation>> RepresentationManager::representations_;

bool RepresentationManager::registerRepresentation(const std::string &key, std::unique_ptr<Representation> representation)
{
    // Insert the representation, returns false if the key already exists
    auto result = representations_.emplace(key, std::move(representation));
    return result.second;
}

Representation *RepresentationManager::representation(const std::string &key)
{
    auto it = representations_.find(key);
    if (it != representations_.end()) {
        return it->second.get();
    }
    return nullptr;
}

} // namespace rep
} // namespace cmd
} // namespace turnip
