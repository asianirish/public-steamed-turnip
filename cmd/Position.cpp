#include "Position.h"

namespace turnip {
namespace cmd {

const int Position::INVALID_POSITION = INT_MIN;

Position::Position(int index) : index_(index) {}

Position::operator int() const
{
    return index_;
}

Position &Position::operator=(int index)
{
    index_ = index;
    return *this;
}

bool Position::isValid() const
{
    return index_ != Position::INVALID_POSITION;
}

} // namespace cmd
} // namespace turnip
