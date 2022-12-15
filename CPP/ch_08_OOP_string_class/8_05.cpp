// STL
#include <iostream>
#include <string>
#include <fstream>
// TPL
#include <fmt/format.h>

// display string statistics
void printStatistics(const std::string &s, std::fstream &file)
{
    file << fmt::format(
        "capacity: {}\nmax size: {}\nsize: {}\nempty: {}",
        s.capacity(), s.max_size(), s.size(), s.empty());
}

int main()
{
    std::fstream file;

    file.open("8_05.txt", std::ios::out);

    if (file.is_open())
    {
        std::string string1; // empty string
        file << "Statistics before input:\n";
        printStatistics(string1, file);

        file << "\n\nEnter a string: ";
        std::cin >> string1; // delimited by whitespace
        file << fmt::format("The string entered was: {}\n", string1);
        file << "Statistics after input:\n";
        printStatistics(string1, file);

        file << "\n\nEnter a string: ";
        std::cin >> string1; // delimited by whitespace
        file << fmt::format("The string entered was: {}\n", string1);
        file << "Statistics after input:\n";
        printStatistics(string1, file);

        // append 46 characters to string1
        string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
        file << fmt::format("\n\nstring1 is now: {}\n", string1);
        file << "Statistics after concatenation:\n";
        printStatistics(string1, file);

        string1.resize(string1.size() + 10); // add 10 elements to string1
        file << "\n\nStatistics after resizing to add 10 characters:\n";
        printStatistics(string1, file);
        file << '\n';

        file.close();
    }
}