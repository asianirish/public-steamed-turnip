#include "HumanStringGenerator.h"

#include <atomic>
#include <chrono>

namespace turnip {
namespace common {

std::atomic<int> callCounter(0);

long long getUniqueMillisecondsSinceEpoch() {
    // Get the current time point using a high-resolution clock
    auto now = std::chrono::high_resolution_clock::now();

    // Convert time point to nanoseconds since the Unix epoch
    auto millisecondsSinceEpoch = std::chrono::duration_cast<std::chrono::milliseconds>(
                                     now.time_since_epoch()
                                     ).count();

    // Increment the call counter to ensure uniqueness
    int uniquePart = callCounter.fetch_add(1, std::memory_order_relaxed);

    // Combine the nanoseconds and the unique counter
    return millisecondsSinceEpoch * 1000 + uniquePart;
}

HumanStringGenerator::HumanStringGenerator() {}

std::string HumanStringGenerator::generate() const
{
    const char digits[] = "abcdefghijklmnopqrstuvwxyz";
    const long long BASE = 26;
    std::string result;
    auto number = getUniqueMillisecondsSinceEpoch();

    while (number != 0) {
        result = result + digits[std::abs(number % BASE)];
        number /= BASE;
    }

    return result;
}

} // namespace common
} // namespace turnip
