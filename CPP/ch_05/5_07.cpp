#include <iostream>
#include <fmt/format.h>

inline double cube(double side)
{
    return side * side * side;
}

int main()
{
    double sideValue;

    std::cout << "Enter the side length of cube: ";
    std::cin >> sideValue;

    std::cout << fmt::format("Volume of cube with side {} is {}\n", sideValue, cube(sideValue));
}