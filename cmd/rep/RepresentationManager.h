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

    // Declare a template method
    template<typename T>
    void print(const T& value);

    template<typename T>
    static bool registerRepresentation();

    // Registers a new representation using its classKey
    // static bool registerRepresentation(std::unique_ptr<Representation> representation);

    // Retrieves a representation by key
    static Representation* representation(const std::string& key);

private:
    static std::unordered_map<std::string, std::unique_ptr<Representation>> representations_;
};

template<typename T>
inline bool RepresentationManager::registerRepresentation()
{
    auto rep = std::make_unique<T>();
    std::string key = rep->classKey();
    auto result = representations_.emplace(key, std::move(rep));
    return result.second;
}




} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // REPRESENTATIONMANAGER_H
