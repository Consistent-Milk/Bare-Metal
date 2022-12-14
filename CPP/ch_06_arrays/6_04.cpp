// STL
#include <iostream>
#include <array>
#include <random>
// TPL
#include <fmt/format.h>

int main()
{
    constexpr size_t arraySize{5};

    // Seeder for PRNG
    std::random_device rd;
    // Seed PRNG engine
    std::default_random_engine engine{rd()};
    // Define PRNG distribution
    std::uniform_int_distribution prng{1, 10};

    std::array<int, arraySize> values{0};

    for (size_t i{0}; i < values.size(); ++i)
    {
        values.at(i) = prng(engine) * i;
    }

    for (const int &value : values)
    {
        std::cout << fmt::format("{}   ", value);
    }

    std::cout << "\n";
}