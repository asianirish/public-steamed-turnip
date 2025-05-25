#include "RandomUtils.h"

#include <random>

namespace turnip {
namespace common {

bool RandomUtils::chance(int numerator, int denominator)
{
    if (denominator <= 0) return false;
    if (numerator <= 0) return false;
    if (numerator >= denominator) return true;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, denominator - 1);
    return distrib(gen) < numerator;
}

bool RandomUtils::chance_bernoulli(double probability)
{
    // Ensure probability is in [0, 1]
    if (probability <= 0.0) return false;
    if (probability >= 1.0) return true;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution dist(probability);
    return dist(gen);
}

bool RandomUtils::chance_uniform(double probability)
{
    // Ensure probability is in [0, 1]
    if (probability <= 0.0) return false;
    if (probability >= 1.0) return true;
    static std::random_device rd;  // Seed for random number engine
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);
    return dist(gen) < probability;
}

RandomUtils::RandomUtils() {}

} // namespace common
} // namespace turnip
