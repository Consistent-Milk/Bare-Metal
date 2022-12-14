#include <iostream>
#include <fmt/format.h>

int main()
{
    int counter{1};

    while (counter <= 10)
    {
        std::cout << fmt::format("{} ", counter);
        ++counter;
    }
}