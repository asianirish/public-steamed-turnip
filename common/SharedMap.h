#ifndef SHAREDMAP_H
#define SHAREDMAP_H

#include <memory>
#include <map>
#include <stdexcept>

namespace turnip {
namespace common {

template<typename Key, typename Value>
class SharedMap {
public:
    // Constructor
    SharedMap() : data_(std::make_shared<std::map<Key, Value>>()) {}

    SharedMap(const std::map<Key, Value> &mp) : data_(std::make_shared<std::map<Key, Value>>(mp)) {}

    // Access value by key
    Value get(const Key& key) const {
        auto it = data_->find(key);
        if (it != data_->end()) {
            return it->second;
        }
        throw std::out_of_range("Key not found");
    }

    // Insert or update value (copy-on-write)
    void set(const Key& key, const Value& value) {
        // Check if a copy is needed (i.e., if we are the only owner)
        if (!data_.unique()) {
            // Create a new copy of the data
            data_ = std::make_shared<std::map<Key, Value>>(*data_);
        }
        (*data_)[key] = value;
    }

    // Check if the map contains a key
    bool contains(const Key& key) const {
        return data_->find(key) != data_->end();
    }

    // Get size of the map
    size_t size() const {
        return data_->size();
    }

    bool empty() const {
        return data_->empty();
    }

    // Provide begin iterator for range-based for loop
    typename std::map<Key, Value>::iterator begin() {
        // Ensure unique ownership for safe modification
        if (!data_.unique()) {
            data_ = std::make_shared<std::map<Key, Value>>(*data_);
        }
        return data_->begin();
    }

    // Provide const begin iterator
    typename std::map<Key, Value>::const_iterator begin() const {
        return data_->begin();
    }

    // Provide end iterator for range-based for loop
    typename std::map<Key, Value>::iterator end() {
        return data_->end();
    }

    // Provide const end iterator
    typename std::map<Key, Value>::const_iterator end() const {
        return data_->end();
    }
private:
    std::shared_ptr<std::map<Key, Value>> data_;
};

} // namespace common
} // namespace turnip

#endif // SHAREDMAP_H
