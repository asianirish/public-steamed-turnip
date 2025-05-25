#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

namespace turnip {
namespace common {

class RandomUtils
{
public:
    // Returns true with probability numerator/denominator
    static bool chance(int numerator, int denominator);

    // Returns true with the given probability (prob in [0.0, 1.0])
    static bool chance_bernoulli(double probability);

    // Returns true with the specified probability (in [0, 1])
    static bool chance_uniform(double probability);

private:
    RandomUtils();


};

} // namespace common
} // namespace turnip

#endif // RANDOMUTILS_H
