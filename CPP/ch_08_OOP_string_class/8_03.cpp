// STL
#include <iostream>
#include <string>
#include <fstream>
// TPL
#include <fmt/format.h>

int main()
{
    std::fstream myFile;
    const std::string s{"airplane"};

    myFile.open("8_03.txt", std::ios::out);

    if (myFile.is_open())
    {
        myFile << fmt::format("Using substr method of the string class\n");
        myFile << fmt::format("substr(start, substring length from start position)\n");
        myFile << fmt::format("(airplane).substr(3, 4)): {}\n", s.substr(3, 4));
        myFile.close();
    }

    return 0;
}