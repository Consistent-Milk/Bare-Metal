// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>
// CH
#include "Account.hpp"

int main()
{
    std::fstream file;

    Account account_1{"John Doe", 50.00};
    Account account_2{"Jane Doe", -7.00};

    file.open("test.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\n\nfstream open\n\n";

        file << fmt::format("Display initial balance of each account object\n");
        file << fmt::format("account_1: {} has balance ${:.2f}\n", account_1.getName(), account_1.getBalance());
        file << fmt::format("account_2: {} has balance ${:.2f}\n\n", account_2.getName(), account_2.getBalance());

        std::cout << "Enter deposit amount for account_1: ";
        double amount;
        std::cin >> amount;
        file << fmt::format("Adding ${:.2f} to account_1 balance\n\n", amount);
        account_1.deposit(amount);

        std::cout << "Enter deposit amount for account_2: ";
        std::cin >> amount;
        file << fmt::format("Adding ${:.2f} to account_2 balance\n\n", amount);
        account_2.deposit(amount);

        file << fmt::format("Display modified balance of each account object\n");
        file << fmt::format("account_1: {} has balance ${:.2f}\n", account_1.getName(), account_1.getBalance());
        file << fmt::format("account_2: {} has balance ${:.2f}\n\n", account_2.getName(), account_2.getBalance());
    }

    file.close();
    std::cout << "\n\nfstream closed\n\n";
}