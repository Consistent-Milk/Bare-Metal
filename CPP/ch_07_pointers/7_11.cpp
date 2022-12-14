// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>

int main()
{
    constexpr char c{};          // variable of type char
    constexpr short s{};         // variable of type short
    constexpr int i{};           // variable of type int
    constexpr long l{};          // variable of type long
    constexpr long long ll{};    // variable of type long long
    constexpr float f{};         // variable of type float
    constexpr double d{};        // variable of type double
    constexpr long double ld{};  // variable of type long double
    constexpr int array[20]{};   // built-in array of int
    const int *const ptr{array}; // variable of type int*

    std::fstream myFile;

    // Open myFile to write output
    myFile.open("7_11.txt", std::ios::out);

    if (myFile.is_open())
    {
        myFile << fmt::format("sizeof c = {}\tsizeof(char) = {}\n",
                              sizeof c, sizeof(char));
        myFile << fmt::format("sizeof s = {}\tsizeof(short) = {}\n",
                              sizeof s, sizeof(short));
        myFile << fmt::format("sizeof i = {}\tsizeof(int) = {}\n",
                              sizeof i, sizeof(int));
        myFile << fmt::format("sizeof l = {}\tsizeof(long) = {}\n",
                              sizeof l, sizeof(long));
        myFile << fmt::format("sizeof ll = {}\tsizeof(long long) = {}\n",
                              sizeof ll, sizeof(long long));
        myFile << fmt::format("sizeof f = {}\tsizeof(float) = {}\n",
                              sizeof f, sizeof(float));
        myFile << fmt::format("sizeof d = {}\tsizeof(double) = {}\n",
                              sizeof d, sizeof(double));
        myFile << fmt::format("sizeof ld = {}\tsizeof(long double) = {}\n",
                              sizeof ld, sizeof(long double));
        myFile << fmt::format("sizeof array = {}\n", sizeof array);
        myFile << fmt::format("sizeof ptr = {}\n", sizeof ptr);

        myFile.close();
    }
}