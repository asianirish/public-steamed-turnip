#ifndef DYN_COMBO_CONTAINER_H
#define DYN_COMBO_CONTAINER_H

#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>

namespace turnip {
namespace common {

template<typename T>
using DynCombo = std::vector<T>;

template<typename T>
class DynComboContainer;

template<typename T>
class DynComboContainerIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = DynCombo<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = DynCombo<T>*;
    using reference = DynCombo<T>&;

    DynComboContainerIterator(const DynComboContainer<T> &container, const DynCombo<T> &curCombo) :
        _container(container),
        _curCombo(curCombo)
    {
    }

    // builds an invalid iterator
    DynComboContainerIterator() = default;

    DynCombo<T> operator*() const {
        return _curCombo;
    }

    const DynCombo<T> &curCombo() const;
    void setCurCombo(const DynCombo<T> &newCurCombo);

    const DynComboContainerIterator<T> &operator++() {
        int i = _curCombo.size() - 1;
        if (!tryToEdit(i)) {
            _curCombo.clear();
        }
        return *this;
    }

    bool operator !=(const DynComboContainerIterator<T> &other) const {
        return (_curCombo != other._curCombo);
    }

private:
    DynComboContainer<T> _container;
    DynCombo<T> _curCombo;

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
/// \brief The DynComboContainer class
///
template<typename T>
class DynComboContainer
{
public:
    DynComboContainer() {}

    DynComboContainer(const std::vector<std::vector<T>> &values)
        : _values(values)
    {}

    using iterator = DynComboContainerIterator<T>;

    inline size_t comboLength() const {
        return _values.size();
    }


    iterator begin() const {
        iterator it(*this, DynCombo<T>());

        size_t comboLength = _values.size();

        if (!_values.empty()) {
            DynCombo<T> combo;
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

    const std::vector<std::vector<T>> &values() const {
        return _values;
    }

private:
    std::vector<std::vector<T>> _values;
};


template<typename T>
const DynCombo<T> &DynComboContainerIterator<T>::curCombo() const
{
    return _curCombo;
}

template<typename T>
void DynComboContainerIterator<T>::setCurCombo(const DynCombo<T> &newCurCombo)
{
    _curCombo = newCurCombo;
}

} // namespace common
} // namespace turnip

#endif // DYN_COMBO_CONTAINER_H

