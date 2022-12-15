// STL
#include <iostream>
#include <fstream>
#include <string>
// TPL
#include <fmt/format.h>

int main()
{
    std::fstream file;

    std::string s1{"one"};
    std::string s2{"two"};

    file.open("8_04.txt", std::ios::out);

    if (file.is_open())
    {
        file << fmt::format("Before swap:\n s1 -> {} \t s2 -> {}\n", s1, s2);
        s1.swap(s2);
        file << fmt::format("After swap:\n s1 -> {} \t s2 -> {}\n", s1, s2);
    }

    file.close();
}