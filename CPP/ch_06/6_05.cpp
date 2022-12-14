// STL
#include <iostream>
#include <array>
#include <random>
// TPL
#include <fmt/format.h>

int main()
{
    constexpr int arraySize{10};

    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution prng{1, 100};

    std::array<int, arraySize> array{0};

    for (size_t i = 0; i < array.size(); ++i)
    {
        array.at(i) = prng(engine);
        std::cout << fmt::format("Index {} -> Value {}\n", i, array.at(i));
    }

    int total{0};
    for (const int &value : array)
    {
        total += value;
    }

    std::cout << fmt::format("Sum of array elements: {}\n", total);
}