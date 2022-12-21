#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#define FMT_HEADER_ONLY
#include <fmt/format.h>

int main()
{
    std::fstream f;
    std::string s1{"Happy"};     // Initialize string from char*
    std::string s2{" Birthday"}; // Initialize string from char*
    std::string s3;
    std::string_view v{"Hello"};

    f.open("11_01.txt", std::ios::out);

    if (f.is_open())
    {
        f << fmt::format("s1: '{}'\ns2: '{}'\ns3: '{}'\nv: '{}'\n", s1, s2, s3, v);

        // Using string.empty() member function

        if (s3.empty())
        {
            f << "s3 is empty; assigning s1 to s3 using the copy assignment operator\n";
            s3 = s1;
            f << fmt::format("s3: '{}'", s3);
        }

        s1 += s2;
        s1 += " to You.";
        s1 += " Have a great day!";

        // Using string.substr() member function
        // string.substr(a, n) return n chars starting including the char at position a
        f << fmt::format("\ns1.substr(0,14): '{}'\n", s1.substr(0, 14));
        // string.substr(a) returns all char after position a including the char at position a
        f << fmt::format("\ns1.substr(15): '{}'\n", s1.substr(15));

        f.close();
    }
    else
    {
        std::cout << "fstream could not be opened, exiting program...";
    }
}