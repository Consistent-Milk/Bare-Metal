#include <iostream>
#include "bignumber.h"

// Important:
// *First read the Readme.md file inside CPP.
// Open this file in integrated terminal then run the below command to use the BigNumber Library and compile this program.
// g++ --std=gnu++23 -I ../libraries/BigNumber/src 3_05.cpp ../libraries/BigNumber/src/bignumber.cpp -o 3_05.exe (Windows)
// g++ --std=gnu++23 -I ../libraries/BigNumber/src 3_05.cpp ../libraries/BigNumber/src/bignumber.cpp -o 3_05 (Linux)
// Enter to run: 3_05.exe (Windows)
// Enter to run: ./3_05 (Linux)

int main()
{
    // use the maximum long long fundamental type value in calculations
    const long long value1{9'223'372'036'854'775'807LL}; // long long max

    // use an arbitrary-precision integer
    const BigNumber value2{value1};
    std::cout << "\n\nBigNumber value2: " << value2
              << "\nvalue2 - 1: " << value2 - 1  // OK
              << "\nvalue2 + 1: " << value2 + 1; // OK

    int counter{2};

    // powers of 100,000,000 with BigNumber
    BigNumber value4{100'000'000};
    std::cout << "\n\nvalue4: " << value4 << "\n";

    counter = 2;

    while (counter <= 5)
    {
        std::cout << "value4.pow(" << counter << "): "
                  << value4.pow(counter) << "\n";
        ++counter;
    }

    std::cout << "\n";
}