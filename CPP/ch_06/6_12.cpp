// STL
#include <array>
#include <iostream>
#include <numeric>
// TPL
#include <fmt/format.h>

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    constexpr size_t arraySize{5};
    constexpr std::array<int, arraySize> integers{1, 2, 3, 4, 5};

    auto product = std::accumulate(std::begin(integers), std::end(integers), 1, multiply);
    std::cout << fmt::format("Product of integers: {}\n", product);

    product = std::accumulate(std::begin(integers), std::end(integers), 1, [](const auto &x, const auto &y)
                              { return x * y; });
    std::cout << fmt::format("Product of integers: {}\n", product);
}