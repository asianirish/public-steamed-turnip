#ifndef SHAREDVECTOR_H
#define SHAREDVECTOR_H

#include <iostream>
#include <memory>
#include <ostream>
#include <vector>
#include <stdexcept>

namespace turnip {
namespace common {

template<typename T>
class SharedVector {
public:
    // Constructor
    SharedVector() : data_(std::make_shared<std::vector<T>>()) {}

    SharedVector(const std::vector<T> &vec) : data_(std::make_shared<std::vector<T>>(vec)) {}

    // SharedVector(const SharedVector &other) : data_(other.data_) {}

    // Access value by index
    T get(size_t index) const {
        if (index < data_->size()) {
            return (*data_)[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Insert or update value at index (copy-on-write)
    void set(size_t index, const T& value) {
        if (index < data_->size()) {
            // Check if a copy is needed
            if (!data_.unique()) {
                // Create a new copy of the data
                data_ = std::make_shared<std::vector<T>>(*data_);
            }
            (*data_)[index] = value;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Add a new element at the end
    void push_back(const T& value) {
        // Ensure unique ownership for safe modification
        if (!data_.unique()) {
            data_ = std::make_shared<std::vector<T>>(*data_);
        }
        data_->push_back(value);
    }

    // Get size of the vector
    size_t size() const {
        return data_->size();
    }

    bool empty() const {
        return data_->empty();
    }

    // Provide begin iterator for range-based for loop
    typename std::vector<T>::iterator begin() {
        return data_->begin();
    }

    // Provide const begin iterator
    typename std::vector<T>::const_iterator begin() const {
        return data_->begin();
    }

    // Provide end iterator for range-based for loop
    typename std::vector<T>::iterator end() {
        return data_->end();
    }

    // Provide const end iterator
    typename std::vector<T>::const_iterator end() const {
        return data_->end();
    }

    void showDataAddress() const {
        std::cout << data_.get() << std::endl;
    }
private:
    std::shared_ptr<std::vector<T>> data_;
};

} // namespace common
} // namespace turnip

#endif // SHAREDVECTOR_H
