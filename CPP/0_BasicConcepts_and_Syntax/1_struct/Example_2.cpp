#include <iostream>

struct Length
{
    int meters;
    float centimeters;
};

int main()
{
    Length *ptr; // A pointer variable to an instance of struct Length
    Length l;    // A normal instance of struct Length

    ptr = &l; // Pointer the pointer ptr to the address of l

    std::cout << "Enter meters: ";
    std::cin >> ptr->meters;
    std::cout << "Enter centimeters: ";
    std::cin >> ptr->centimeters;
    std::cout << "Length = " << ptr->meters << " meters " << ptr->centimeters << " centimeters";

    return 0;
}