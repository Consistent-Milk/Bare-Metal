// STL
#include <array>
#include <iostream>
#include <numeric>
// TPL
#include <fmt/format.h>

int main()
{
    constexpr std::array<int, 4> integers{10, 20, 30, 40};

    auto total = std::accumulate(std::begin(integers), std::end(integers), 0);

    std::cout << fmt::format("Total of array elements: {}\n", total);
}