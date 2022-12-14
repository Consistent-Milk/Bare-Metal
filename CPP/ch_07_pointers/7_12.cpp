// STL
#include <array>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>
#include <fstream>
#include <random>
// TPL
#include <fmt/format.h>

// Important : Only pass a reference(&file) to the open file not the file itself(file)
void displayArray(const int items[], size_t size, std::fstream &file)
{
    for (size_t i{0}; i < size; ++i)
    {
        file << fmt::format("{} ", items[i]);
    }
}

void displaySpan(std::span<const int> items, std::fstream &file)
{
    for (const auto &item : items)
    {
        file << fmt::format("{} ", item);
    }
}

void times2(std::span<int> items)
{
    for (int &item : items)
    {
        item *= 2;
    }
}

int main()
{
    std::fstream myFile;
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution prng{1, 20};

    constexpr size_t arraySize{5};

    int array_1[arraySize]{0};
    std::array<int, arraySize> array_2{0};
    std::vector<int> array_3(arraySize);

    for (size_t i = 0; i < arraySize; ++i)
    {
        int rand_val = prng(engine);
        array_1[i] = rand_val;
        array_2[i] = rand_val;
        array_3[i] = rand_val;
    }

    myFile.open("7_12.txt", std::ios::out);

    if (myFile.is_open())
    {
        myFile << "array_1 via displayArray: ";
        displayArray(array_1, arraySize, myFile);

        myFile << "\narray_1 via displaySpan: ";
        displaySpan(array_1, myFile);

        myFile << "\narray_2 via displaySpan: ";
        displaySpan(array_2, myFile);

        myFile << "\narray_3 via displaySpan: ";
        displaySpan(array_3, myFile);

        times2(array_1);
        myFile << "\n\narray_1 after times2 modifies its span argument: ";
        displaySpan(array_1, myFile);

        myFile.close();
    }
}