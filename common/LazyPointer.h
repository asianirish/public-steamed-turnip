#ifndef LAZYPOINTER_H
#define LAZYPOINTER_H

#include "Factory.h"

#include <memory>
#include <string>

namespace turnip {
namespace common {

template <class Base>
class LazyPointer
{
public:
    LazyPointer() = default;

    LazyPointer(const std::string &defaultClassName) : className_(defaultClassName) {}

    std::string className() const {
        return className_;
    }

    void setClassName(const std::string &className) {
        className_ = className;
    }

    std::shared_ptr<Base> ptr() const {
        if (!ptr_) {
            ptr_ = std::shared_ptr<Base>(createPtr());
        }
        return ptr_;
    }

    std::shared_ptr<Base> operator->() {
        return ptr();
    }

    const std::shared_ptr<Base> operator->() const {
        return ptr();
    }

    operator bool() const {
        return ptr_ != nullptr;
    }

    bool isNull() const {
        return !ptr_;
    }

    template<class Child>
    std::shared_ptr<Child> dynamicCast() {
        return std::dynamic_pointer_cast<Child>(ptr());
    }

private:
    std::string className_;
    mutable std::shared_ptr<Base> ptr_;

    Base* createPtr() const {
        return Factory<Base>::create(className_);
    }
};

} // namespace common
} // namespace turnip

#endif // LAZYPOINTER_H
