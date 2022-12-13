// fig02_06.cpp
// Standard library string class test program.
#include <iostream>
#include <string>

int main()
{
    std::string s1{"happy"};
    std::string s2{" birthday"};
    std::string s3; // creates an empty string

    // display the strings and show their lengths (length is C++20)
    std::cout << "s1: \"" << s1 << "\"; length: " << s1.length()
              << "\ns2: \"" << s2 << "\"; length: " << s2.length()
              << "\ns3: \"" << s3 << "\"; length: " << s3.length();

    // compare strings with == and !=
    std::cout << "\n\nThe results of comparing s2 and s1:" << std::boolalpha
              << "\ns2 == s1: " << (s2 == s1)
              << "\ns2 != s1: " << (s2 != s1);

    // test string member function empty
    std::cout << "\n\nTesting s3.empty():\n";

    if (s3.empty())
    {
        std::cout << "s3 is empty; assigning to s3;\n";
        s3 = s1 + s2; // assign s3 the result of concatenating s1 and s2
        std::cout << "s3: \"" << s3 << "\"";
    }

    // testing new C++20 string member functions
    std::cout << "\n\ns1 starts with \"ha\": " << s1.starts_with("ha") << "\n";
    std::cout << "s2 starts with \"ha\": " << s2.starts_with("ha") << "\n";
    std::cout << "s1 ends with \"ay\": " << s1.ends_with("ay") << "\n";
    std::cout << "s2 ends with \"ay\": " << s2.ends_with("ay") << "\n";
}
