// STDL
#include <iostream>
#include <array>
// TPL
#include <fmt/format.h>

int main()
{
    // Brace Initializer
    std::array<int, 5> values{1, 2, 3, 4, 5};

    for (size_t i{0}; i < values.size(); ++i)
    {
        std::cout << fmt::format("{}  ", values.at(i));
    }

    std::cout << "\n\n";

    // Using class template argument deduction to determine
    // values2's type
    std::array values2{1.2, 2.2, 3.3, 4.4};

    for (size_t i{0}; i < values2.size(); ++i)
    {
        std::cout << fmt::format("{}   ", values2.at(i));
    }

    std::cout << "\n";
}