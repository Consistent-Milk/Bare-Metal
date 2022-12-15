// STL
#include <iostream>
#include <string>
#include <fstream>
// TPL
#include <fmt/format.h>

void displayResult(const std::string &s, int result, std::fstream &file)
{
    if (result == 0)
    {
        file << fmt::format("{} == 0\n", s);
    }
    else if (result > 0)
    {
        file << fmt::format("{} > 0\n", s);
    }
    else
    {
        file << fmt::format("{} < 0\n", s);
    }
}

int main()
{
    std::fstream myFile;
    const std::string s1{"Testing the comparison functions"};
    const std::string s2{"Hello"};
    const std::string s3{"stranger"};
    const std::string s4{s2};

    myFile.open("8_02.txt", std::ios::out);

    if (myFile.is_open())
    {
        myFile << fmt::format("s1: {}\ns2: {}\ns3: {}\ns4: {}", s1, s2, s3, s4);
    }

    myFile << "\nComparing s1 and s3\n";
    displayResult("s1.compare(s2):", s1.compare(s2), myFile);

    myFile << "\nComparing s1 (elements 2-6) and s3 (elements 0-4)\n";
    displayResult("s1.compare(2, 5, s3, 0, 5)",
                  s1.compare(2, 5, s3, 0, 5), myFile);

    myFile << "\nComparing s2 and s4\n";
    displayResult("s4.compare(0, s2.size(), s2)",
                  s4.compare(0, s2.size(), s2), myFile);

    myFile << "\nComparing s2 and s4\n";
    displayResult("s2.compare(0, 3, s4)", s2.compare(0, 3, s4), myFile);

    myFile.close();
}