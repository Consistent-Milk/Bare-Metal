// STDL
#include <iostream>
#include <array>
#include <random>
#include <fstream>
// TPL
#include <fmt/format.h>

int main()
{
    // Seed for PRNG
    std::random_device rd;
    // Seed PRNG engine
    std::default_random_engine engine(rd());
    // Define PRNG distribution
    std::uniform_int_distribution prng{1, 100};
    std::fstream myFile;
    std::array<int, 5> values;

    // Initialize all elements of array to 0
    for (size_t i{0}; i < values.size(); ++i)
    {
        // Get random values from PRNG distribution
        values[i] = prng(engine);
    }

    // Saving output to .txt files instead of just using the cmd
    myFile.open("6_01.txt", std::ios::out);

    if (myFile.is_open())
    {
        // Header
        myFile << fmt::format("{:>7}{:>10}\n", "Element", "Value");

        // Output array elements
        for (size_t i{0}; i < values.size(); ++i)
        {
            myFile << fmt::format("{:>7}{:>10}\n", i, values[i]);
        }

        // Header
        myFile << fmt::format("\n{:>7}{:>10}\n", "Element", "Value");

        // Output array elements using 'at()' method
        for (size_t i{0}; i < values.size(); ++i)
        {
            myFile << fmt::format("{:>7}{:>10}\n", i, values.at(i));
        }

        myFile.close();
    }

    return 0;
}