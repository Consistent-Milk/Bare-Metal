#include <fmt/format.h>
#include <iostream>

size_t getSize(double *ptr);

int main()
{
    double numbers[20];

    std::cout << fmt::format("Number of bytes in numbers is {}\n\n", sizeof(numbers));

    std::cout << fmt::format("Number of bytes returned by getSize is {}\n", getSize(numbers));
}

// return size of ptr
size_t getSize(double *ptr)
{
    return sizeof(ptr);
}
