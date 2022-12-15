// STL
#include <iostream>
#include <fstream>
#include <vector>
// TPL
#include <fmt/format.h>
#include <rapidcsv.h>

int main()
{
    std::fstream file;

    rapidcsv::Document document{"accounts.csv"}; // loads accounts.csv
    std::vector<int> accounts{document.GetColumn<int>("account")};
    std::vector<std::string> names{
        document.GetColumn<std::string>("name")};
    std::vector<double> balances{document.GetColumn<double>("balance")};

    file.open("8_14.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\n\nfstream open\n\n";

        file << fmt::format(
            "{:<10}{:<13}{:>7}\n", "Account", "Name", "Balance");

        for (size_t i{0}; i < accounts.size(); ++i)
        {
            file << fmt::format("{:<10}{:<13}{:>7.2f}\n",
                                accounts.at(i), names.at(i), balances.at(i));
        }
    }

    file.close();
    std::cout << "\n\nfstream closed\n\n";
}
