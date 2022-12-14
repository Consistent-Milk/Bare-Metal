#include <iostream>
#include <iomanip>
#include <cmath> // for pow function
#include <fmt/format.h>

int main()
{
    // set floating-point number format
    std::cout << std::fixed << std::setprecision(2);

    double principal{1000.00}; // initial amount before interest
    double rate{0.05};         // interest rate

    std::cout << fmt::format("Initial principal: {} \n", principal);
    std::cout << fmt::format("Interest Rate: {} \n", rate);

    // display headers
    std::cout << "\nYear" << std::setw(20) << "Amount on deposit"
              << "\n";

    // calculate amount on deposit for each of ten years
    for (int year{1}; year <= 10; ++year)
    {
        // calculate amount on deposit at the end of the specified year
        double amount{principal * pow(1.0 + rate, year)};

        // display the year and the amount
        std::cout << std::setw(4) << year << std::setw(20) << amount << "\n";
    }
}