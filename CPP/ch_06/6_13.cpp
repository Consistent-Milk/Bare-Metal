// STL
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
// TPL
#include <fmt/format.h>

int main()
{
    // Lambda function to generate a input message
    // followed by printing out values of an input array
    auto showValues{
        [](auto &values, const std::string &message)
        {
            std::cout << fmt::format("{}: ", message);

            for (const auto &value : values)
            {
                std::cout << fmt::format("{} ", value);
            }
            std::cout << "\n";
        }};

    auto array1 = std::views::iota(1, 11);
    showValues(array1, "Generate integers 1-10");

    // Lambda function to filter even integers
    auto array2 = array1 | std::views::filter(
                               [](const auto &x)
                               { return x % 2 == 0; });
    showValues(array2, "Filtering even integers");

    // Lambda function to map square even integers
    auto array3 = array2 | std::views::transform(
                               [](const auto &x)
                               { return x * x; });
    showValues(array3, "Mapping even integers to squares");
}