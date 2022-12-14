// STDL
#include <iostream>
#include <array>
#include <random>
// TPL
#include <fmt/format.h>

int main()
{
    // Seed for PRNG
    std::random_device rd;
    // Seed PRNG engine
    std::default_random_engine engine(rd());
    // Define PRNG distribution
    std::uniform_int_distribution prng{1, 100};
    std::array<int, 5> values;

    // Initialize all elements of array to 0
    for (size_t i{0}; i < values.size(); ++i)
    {
        // Get random values from PRNG
        values[i] = prng(engine);
    }

    // Header
    std::cout << fmt::format("{:>7}{:>10}\n", "Element", "Value");

    // Output array elements
    for (size_t i{0}; i < values.size(); ++i)
    {
        std::cout << fmt::format("{:>7}{:>10}\n", i, values[i]);
    }

    // Header
    std::cout << fmt::format("\n{:>7}{:>10}\n", "Element", "Value");

    // Output array elements using 'at()' method
    for (size_t i{0}; i < values.size(); ++i)
    {
        std::cout << fmt::format("{:>7}{:>10}\n", i, values.at(i));
    }

    return 0;
}