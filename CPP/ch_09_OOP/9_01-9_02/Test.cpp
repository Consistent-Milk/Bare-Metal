// STL
#include <iostream>
#include <string>
#include <fstream>
// TPL
#include <fmt/format.h>
// Custom Headers
#include "Account.hpp"

int main()
{
    std::fstream file;
    Account myAccount{};

    file.open("test.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "fstream open\n\n";

        file << fmt::format("Initial account name: {}\n", myAccount.getName());

        std::cout << "Enter account name: ";
        std::string name{};
        std::getline(std::cin, name);
        myAccount.setName(name);

        file << fmt::format("Updated account name is: {}\n", myAccount.getName());

        file.close();

        std::cout << "\n\nfstream closed\n\n";
    }
}