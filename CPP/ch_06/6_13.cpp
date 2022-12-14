// STL
#include <array>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <random>
// TPL
#include <fmt/format.h>

int main()
{
    std::cout << "\n\n";

    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution prng{1, 100};

    // lambda to display results of range operations
    auto showValues{
        [](auto &values, const std::string &message)
        {
            std::cout << fmt::format("{}: ", message);

            for (const auto &value : values)
            {
                std::cout << fmt::format("{} ", value);
            }

            std::cout << '\n';
        }};

    auto array1 = std::views::iota(1, 11); // generate integers 1-10
    showValues(array1, "Generate integers 1-10");

    // filter each value in values1, keeping only the even integers
    auto array2 = array1 |
                  std::views::filter([](const auto &x)
                                     { return x % 2 == 0; });
    showValues(array2, "Filtering even integers");

    // map each value in values2 to its square
    auto array3 =
        array2 | std::views::transform([](const auto &x)
                                       { return x * x; });
    showValues(array3, "Mapping even integers to squares");

    // combine filter and transform to get squares of the even integers
    auto array4 = array1 | std::views::filter([](const auto &x)
                                              { return x % 2 == 0; }) |
                  std::views::transform([](const auto &x)
                                        { return x * x; });
    showValues(array4, "Squares of even integers");

    auto total = std::accumulate(std::begin(array4), std::end(array4), 0);
    std::cout << fmt::format("Sum of squares of even integers from 2 to 10: {}\n", total);

    constexpr size_t arraySize{20};
    std::array<int, arraySize> array5{0};

    for (int &val : array5)
    {
        val = prng(engine);
    }

    std::cout << fmt::format("\nUnmodified random array:\n");
    for (int &val : array5)
    {
        std::cout << val << "  ";
    }

    // Sort
    std::sort(std::begin(array5), std::end(array5));

    std::cout << fmt::format("\nSorted random array:\n");
    for (int &val : array5)
    {
        std::cout << val << "  ";
    }
    std::cout << "\n";

    // Combine Filter, Transform and Accumulate to find sum of squares of odd numbers
    auto array6 = array5 | std::views::filter([](const auto &x)
                                              { return x % 2 != 0; }) |
                  std::views::transform([](const auto &x)
                                        { return x * x; });
    showValues(array6, "Squares of odd numbers of random array");

    total = std::accumulate(std::begin(array6), std::end(array6), 0);
    std::cout << fmt::format("\nThe sum of squares of odd numbers of the random array is {}", total);

    std::cout << "\n\n";
}
