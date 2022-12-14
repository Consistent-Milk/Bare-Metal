// STL
#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
// TPL
#include <fmt/format.h>

void outputVector(const std::vector<int> &items);

int main()
{
    std::cout << "\n\n";

    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution prng{1, 100};

    std::vector<int> integers1(7);
    std::vector<int> integers2(10);

    std::cout << fmt::format("Size of vector integers1 is {}", integers1.size());
    std::cout << "\nvector after initialization:";
    outputVector(integers1);

    std::cout << fmt::format("Size of vector integers1 is {}", integers2.size());
    std::cout << "\nvector after initialization:";
    outputVector(integers2);

    // Modify vectors with random values
    for (int &x : integers1)
    {
        x = prng(engine);
    }

    for (int &x : integers2)
    {
        x = prng(engine);
    }

    std::cout << "\nAfter modification the vectors contain:\n"
              << "integers1: ";
    outputVector(integers1);
    std::cout << "integers2: ";
    outputVector(integers2);

    // Use of stdexcept library
    // Attempting to acces out of bounds index of a vector
    try
    {
        std::cout << fmt::format("Attempt to display integers1.at(15) = {}\n", integers1.at(15)) << "\n";
    }
    catch (const std::out_of_range &ex)
    {
        std::cerr << fmt::format("An exception occurred: {}\n", ex.what());
    }

    // changing the size of a vector
    std::cout << "\nCurrent integers3 size is: " << integers2.size();
    integers2.push_back(1000); // add 1000 to the end of the vector
    std::cout << "\nNew integers3 size is: " << integers2.size()
              << "\nintegers3 now contains: ";
    outputVector(integers2);

    std::cout << "\n\n";
}

void outputVector(const std::vector<int> &items)
{
    for (const int &item : items)
    {
        std::cout << item << " ";
    }

    std::cout << "\n";
}
