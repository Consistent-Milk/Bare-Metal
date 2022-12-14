#include <iostream>
#include <fstream>

int main()
{
    std::fstream myFile;

    constexpr int a{7};
    const int *aPtr{&a};

    myFile.open("7_01.txt", std::ios::out);
    if (myFile.is_open())
    {
        myFile << "The address of a is " << &a << "\n";
        myFile << "The value of aPtr is " << aPtr << "\n";
        myFile << "The value of a is" << a << "\n";
        myFile << "The value of *aPtr is " << *aPtr << "\n";

        myFile.close();
    }
}