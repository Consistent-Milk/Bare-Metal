#include <fmt/format.h>
#include <iostream>

void cubeByReference(int *nPtr); // prototype

int main()
{
    int number{5};

    std::cout << fmt::format("Original value of number is {}\n", number);
    cubeByReference(&number); // pass number address to cubeByReference
    std::cout << fmt::format("New value of number is {}\n", number);
}

// Pointer arithmetic, modifies the value stored in the address
// the pointer is pointing to
void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
}