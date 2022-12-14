#include <iostream>
#include <array>

constexpr size_t rows{2};
constexpr size_t columns{3};
void printArray(const std::array<std::array<int, columns>, rows> &a);

int main()
{
    constexpr std::array array1{std::array{1, 2, 3}, std::array{4, 5, 6}};
    constexpr std::array array2{std::array{1, 2, 3}, std::array{4, 5, 0}};

    std::cout << "array1 by row:\n";
    printArray(array1);

    std::cout << "\narray2 by row:\n";
    printArray(array2);
}

// output array with two rows and three columns
void printArray(const std::array<std::array<int, columns>, rows> &a)
{
    // loop through array's rows
    for (const auto &row : a)
    {
        // loop through columns of current row
        for (const auto &element : row)
        {
            std::cout << element << " ";
        }

        std::cout << "\n"; // start new line of output
    }
}
