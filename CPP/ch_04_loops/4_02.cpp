#include <iostream>
#include <fmt/format.h>

int main()
{
    for (int counter{1}; counter <= 10; ++counter)
    {
        std::cout << fmt::format("{} ", counter);
    }

    std::cout << "\n";
}