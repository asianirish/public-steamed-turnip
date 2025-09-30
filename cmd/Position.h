#ifndef POSITION_H
#define POSITION_H

#include <climits>

namespace turnip {
namespace cmd {

class Position
{
public:
    static const int INVALID_POSITION;

    // Constructor to initialize the Position with an integer value
    explicit Position(int index = Position::INVALID_POSITION);

    // Conversion operator to convert Position to int
    operator int() const;

    // Assignment operator to assign an int value to Position
    Position& operator=(int index);

    bool isValid() const;

private:
    int index_ {Position::INVALID_POSITION};
};

// User-defined literal operator for Position
inline Position operator""_pos(unsigned long long int index) {
    return Position(static_cast<int>(index));
}

} // namespace cmd
} // namespace turnip

#endif // POSITION_H
