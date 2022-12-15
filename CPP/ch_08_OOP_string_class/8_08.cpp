// STL
#include <iostream>
#include <string>
#include <fstream>
// TPL
#include <fmt/format.h>

int main()
{
    std::fstream file;

    std::string s1{"beginning end"};
    std::string s2{"12345678"};

    file.open("8_08.txt", std::ios::out);

    if (file.is_open())
    {
        file << fmt::format("Initial strings:\ns1: {}\ns2: {}\n\n",
                            s1, s2);

        file << fmt::format("insert \"middle\" at location 10\n");
        s1.insert(10, "middle ");
        file << fmt::format("insert \"xx\" at location 3\n");
        s2.insert(3, "xx", 0, std::string::npos);

        file << fmt::format("Strings after insert:\ns1: {}\ns2: {}\n",
                            s1, s2);

        file.close();
    }
}