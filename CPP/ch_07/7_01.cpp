#include <iostream>

int main()
{
    std::cout << "\n\n";

    constexpr int a{7};
    const int *aPtr{&a};

    std::cout << "The address of a is " << &a << "\n";
    std::cout << "The value of aPtr is " << aPtr << "\n";
    std::cout << "The value of a is" << a << "\n";
    std::cout << "The value of *aPtr is " << *aPtr << "\n";

    std::cout << "\n\n";
}