// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>
// Custom Headers
#include "Account.hpp"

int main()
{
    std::fstream file;

    Account account1{"Jane Doe"};
    Account account2{"John Doe"};

    file.open("test.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\n\nfstream open\n\n";

        file << fmt::format("account1 name is: {}\n", account1.getName());
        file << fmt::format("account2 name is: {}\n", account2.getName());

        file.close();

        std::cout << "fstream closed\n\n";
    }
}