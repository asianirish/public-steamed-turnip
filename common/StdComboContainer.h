#ifndef STD_COMBO_CONTAINER_H
#define STD_COMBO_CONTAINER_H

#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>

namespace turnip {
namespace common {

template<typename T>
using StdCombo = std::vector<T>;

template<typename T>
class StdComboContainer;

template<typename T>
class StdComboContainerIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = StdCombo<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = StdCombo<T>*;
    using reference = StdCombo<T>&;

    StdComboContainerIterator(const StdComboContainer<T> &container, const StdCombo<T> &curCombo) :
        _container(container),
        _curCombo(curCombo)
    {
    }

    // builds an invalid iterator
    StdComboContainerIterator() = default;

    StdCombo<T> operator*() const {
        return _curCombo;
    }

    const StdCombo<T> &curCombo() const;
    void setCurCombo(const StdCombo<T> &newCurCombo);

    const StdComboContainerIterator<T> &operator++() {
        int i = _curCombo.size() - 1;
        if (!tryToEdit(i)) {
            _curCombo.clear();
        }
        return *this;
    }

    bool operator !=(const StdComboContainerIterator<T> &other) const {
        return (_curCombo != other._curCombo);
    }

private:
    StdComboContainer<T> _container;
    StdCombo<T> _curCombo;

    T maxValue() const {
        return _container.values().back();
    }
    T minValue() const {
        return _container.values().front();
    }

    T nextValue(const T &value) const {
        auto it = std::find(_container.values().begin(), _container.values().end(), value);

        if (it == _container.values().end() || (it + 1) == _container.values().end()) {
            throw std::out_of_range("this is the last value");
        }

        return *(it + 1);
    }

    bool tryToEdit(int index) {
        if (_curCombo.empty()) {
            return false;
        }

        auto curValue = _curCombo.at(index);

        if (index == 0 && curValue == maxValue()) {
            return false;
        }

        if (curValue == maxValue()) {
            if (tryToEdit(index - 1)) {
                _curCombo[index] = minValue();
                return true;
            }

            return false;
        }

        _curCombo[index] = nextValue(curValue);
        return true;
    }
};

/////////////////////////////////////
/// \brief The StdComboContainer class
///
template<typename T>
class StdComboContainer
{
public:
    StdComboContainer() : _comboLength(0) {}

    StdComboContainer(const std::vector<T> &values, size_t comboLength)
        : _values(values),
        _comboLength(comboLength)
    {}

    using iterator = StdComboContainerIterator<T>;

    size_t comboLength() const {
        return _comboLength;
    }

    void setComboLength(size_t newLength) {
        _comboLength = newLength;
    }

    iterator begin() const {
        iterator it(*this, StdCombo<T>());

        if (!_values.empty()) {
            StdCombo<T> combo;
            T firstValue = _values.front();
            for (size_t i = 0; i < _comboLength; i++) {
                combo.push_back(firstValue);
            }
            it.setCurCombo(combo);
            return it;
        }

        return {};
    }

    iterator end() const {
        return iterator();
    }

    const std::vector<T> &values() const {
        return _values;
    }

private:
    std::vector<T> _values;
    size_t _comboLength;
};


template<typename T>
const StdCombo<T> &StdComboContainerIterator<T>::curCombo() const
{
    return _curCombo;
}

template<typename T>
void StdComboContainerIterator<T>::setCurCombo(const StdCombo<T> &newCurCombo)
{
    _curCombo = newCurCombo;
}

} // namespace common
} // namespace turnip

#endif // STD_COMBO_CONTAINER_H
