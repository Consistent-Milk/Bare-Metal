// STL
#include <iostream>
#include <array>
// TPL
#include <fmt/format.h>

int main()
{
    // Array type and size implicitly inferred as array<int, 5>
    std::array items{1, 2, 3, 4, 5};

    // display items before modification
    std::cout << "Items before modification: ";
    for (const int &item : items)
    { // item is a reference to a const int
        std::cout << fmt::format("{} ", item);
    }

    // multiply the elements of items by 2
    for (int &item : items)
    { // item is a reference to an int
        item *= 2;
    }

    // display items after modification
    std::cout << "\nItems after modification: ";
    for (const int &item : items)
    {
        std::cout << fmt::format("{} ", item);
    }

    // sum elements of items using range-based for with initialization
    std::cout << "\n\nCalculating the cumulative sum of items' values:\n";

    int arrayIndex{0};

    for (int runningTotal{0}; const int &item : items)
    {
        runningTotal += item;
        std::cout << fmt::format("|Array Index {} -> item: {} -> Cumulative Sum: {}|\n", arrayIndex,
                                 item, runningTotal);
        arrayIndex += 1;
    }
}