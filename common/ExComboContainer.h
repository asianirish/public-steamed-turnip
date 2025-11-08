#ifndef EX_COMBO_CONTAINER_H
#define EX_COMBO_CONTAINER_H

#include <vector>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>

namespace turnip {
namespace common {

template<typename T>
using ExCombo = std::vector<T>;

template<template<typename, typename...> class Container, typename T>
class ExComboContainer;

template<template<typename, typename...> class Container, typename T>
class ExComboContainerIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = ExCombo<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = ExCombo<T>*;
    using reference = ExCombo<T>&;

    ExComboContainerIterator(const ExComboContainer<Container, T> &container, const ExCombo<T> &curCombo) :
        _container(container),
        _curCombo(curCombo)
    {
    }

    // builds an invalid iterator
    ExComboContainerIterator() = default;

    ExCombo<T> operator*() const {
        return _curCombo;
    }

    const ExCombo<T> &curCombo() const;
    void setCurCombo(const ExCombo<T> &newCurCombo);

    const ExComboContainerIterator<Container, T> &operator++() {
        int i = _curCombo.size() - 1;
        if (!tryToEdit(i)) {
            _curCombo.clear();
        }
        return *this;
    }

    bool operator !=(const ExComboContainerIterator<Container, T> &other) const {
        return (_curCombo != other._curCombo);
    }

private:
    ExComboContainer<Container, T> _container;
    ExCombo<T> _curCombo;

    T maxValue(int index) const {
        return _container.values()[index].back();
    }
    T minValue(int index) const {
        return _container.values()[index].front();
    }

    T nextValue(const T &value, int index) const {
        auto it = std::find(_container.values()[index].begin(), _container.values()[index].end(), value);

        if (it == _container.values()[index].end() || (++it) == _container.values()[index].end()) {
            throw std::out_of_range("this is the last value");
        }

        return *(it);
    }

    bool tryToEdit(int index) {
        if (_curCombo.empty()) {
            return false;
        }

        auto curValue = _curCombo.at(index);

        if (index == 0 && curValue == maxValue(index)) {
            return false;
        }

        if (curValue == maxValue(index)) {
            if (tryToEdit(index - 1)) {
                _curCombo[index] = minValue(index);
                return true;
            }

            return false;
        }

        _curCombo[index] = nextValue(curValue, index);
        return true;
    }
};

/////////////////////////////////////
/// \brief The ExComboContainer class
///
template<template<typename, typename...> class Container, typename T>
class ExComboContainer
{
public:
    ExComboContainer() {}

    ExComboContainer(const std::vector<Container<T>> &values)
        : _values(values)
    {}

    using iterator = ExComboContainerIterator<Container, T>;

    inline size_t comboLength() const {
        return _values.size();
    }


    iterator begin() const {
        iterator it(*this, ExCombo<T>());

        size_t comboLength = _values.size();

        if (!_values.empty()) {
            ExCombo<T> combo;
            for (size_t i = 0; i < comboLength; i++) {
                combo.push_back(_values[i].front());
            }
            it.setCurCombo(combo);
            return it;
        }

        return {};
    }

    iterator end() const {
        return iterator();
    }

    const std::vector<Container<T>> &values() const {
        return _values;
    }

private:
    std::vector<Container<T>> _values;
};


template<template<typename, typename...> class Container, typename T>
const ExCombo<T> &ExComboContainerIterator<Container, T>::curCombo() const
{
    return _curCombo;
}

template<template<typename, typename...> class Container, typename T>
void ExComboContainerIterator<Container, T>::setCurCombo(const ExCombo<T> &newCurCombo)
{
    _curCombo = newCurCombo;
}

} // namespace common
} // namespace turnip

#endif // EX_COMBO_CONTAINER_H

