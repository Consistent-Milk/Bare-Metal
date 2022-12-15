#include <iostream>
#include <format>

int main(int, char **)
{
    int a = 1;
    std::cout << std::format("Hello {} {}", "World", a);
}
