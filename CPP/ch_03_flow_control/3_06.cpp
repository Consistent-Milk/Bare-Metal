#include <iostream>
#include <string>
#include <string_view>
#include <fmt/format.h>

// g++ --std=gnu++23 -I ../libraries/fmt/include 3_06.cpp ../libraries/fmt/src/format.cc -o 3_06.exe

int main()
{
    std::string student{"Milk"};
    int grade{100};

    std::cout << fmt::format("\n{}'s grade is {}\n\n", student, grade);
}