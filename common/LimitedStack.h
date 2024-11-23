#ifndef LIMITEDSTACK_H
#define LIMITEDSTACK_H

#include <iostream>
#include <deque>

namespace turnip {
namespace common {

template<typename T>
class LimitedStack {
public:
    explicit LimitedStack(size_t maxSize) : maxSize_(maxSize) {}

    void push(const T& value) {
        if(stack_.size() == maxSize_) {
            stack_.pop_front();  // Remove the oldest element to maintain the size
        }
        stack_.push_back(value);
    }

    void push_front(const T& value) {
        if (stack_.size() == maxSize_) {
            stack_.pop_back();  // Remove the newest element from the back
        }
        stack_.push_front(value);  // Add new element to the front
    }

    void pop() {
        if (!stack_.empty()) {
            stack_.pop_back();
        }
    }

    T& top() {
        return stack_.back();
    }

    bool empty() const {
        return stack_.empty();
    }

    size_t size() const {
        return stack_.size();
    }

    void print() const;

    const T &at(size_t n) {
        return stack_.at(n);
    }

    const T &back() const {
        return stack_.back();
    }

    // Provide begin iterator for range-based for loop
    typename std::deque<T>::iterator begin() {
        return stack_.begin();
    }

    // Provide const begin iterator
    typename std::deque<T>::const_iterator begin() const {
        return stack_.begin();
    }

    // Provide end iterator for range-based for loop
    typename std::deque<T>::iterator end() {
        return stack_.end();
    }

    // Provide const end iterator
    typename std::deque<T>::const_iterator end() const {
        return stack_.end();
    }

private:
    std::deque<T> stack_;
    size_t maxSize_;
};

template<typename T>
void LimitedStack<T>::print() const {
    for (auto value : stack_) {
        std::cout << value << std::endl;
    }
}

} // namespace common
} // namespace turnip

#endif // LIMITEDSTACK_H
