#include <iostream>
#include <fmt/format.h>

int main()
{
    int total{0};

    for (int number{2}; number <= 20; number += 2)
    {
        total += number;
    }

    std::cout << fmt::format("The sum of even integers from 2-20 is = {}", total);

    std::cout << "\n";
}