// STL
#include <iostream>
#include <fstream>
#include <sstream> // header for string stream processing
#include <string>

int main()
{
    std::fstream file;
    std::ostringstream output; // create ostringstream object

    const std::string string1{"Output of several data types "};
    const std::string string2{"to an ostringstream object:"};
    const std::string string3{"\ndouble: "};
    const std::string string4{"\n   int: "};

    constexpr double d{123.4567};
    constexpr int i{22};

    // output strings, double and int to ostringstream
    output << string1 << string2 << string3 << d << string4 << i;

    file.open("8_12.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\n\nfstream open\n\n";

        file << "call str to obtain string contents of the ostringstream\n";
        file << "output contains:\n"
             << output.str();

        file << "\nadd additional characters and call str to output string\n";
        output << "\nmore characters added";
        file << "\n\noutput now contains:\n"
             << output.str() << '\n';
    }

    file.close();
    std::cout << "\n\nfstream closed\n\n";
}