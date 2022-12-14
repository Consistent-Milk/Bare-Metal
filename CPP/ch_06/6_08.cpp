// STL
#include <array>
#include <algorithm> // contains sort and binary_search
#include <iostream>
#include <string>
// TPL
#include <fmt/format.h>

int main()
{
    using namespace std::string_literals; // enables string object literals

    // colors is inferred to be an array<string, 7>
    std::array colors{"red"s, "orange"s, "yellow"s,
                      "green"s, "blue"s, "indigo"s, "violet"s};

    // output original array
    std::cout << "Unsorted colors array:\n   ";
    for (const std::string &color : colors)
    {
        std::cout << fmt::format("{} ", color);
    }

    // sort contents of colors
    std::sort(std::begin(colors), std::end(colors));

    // output sorted array
    std::cout << "\nSorted colors array:\n   ";
    for (const std::string &color : colors)
    {
        std::cout << fmt::format("{} ", color);
    }

    // search for "indigo" in colors
    bool found{std::binary_search(
        std::begin(colors), std::end(colors), "indigo")};
    std::cout << fmt::format("\n\n\"indigo\" {} found in colors array\n",
                             found ? "was" : "was not");

    // search for "cyan" in colors
    found = std::binary_search(
        std::begin(colors), std::end(colors), "cyan");
    std::cout << fmt::format("\"cyan\" {} found in colors array\n",
                             found ? "was" : "was not");
}