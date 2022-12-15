/*
Notes on std::string_view:
The class template basic_string_view describes an object that can refer to a constant contiguous sequence of char-like objects with the first element of the sequence at position zero.
A typical implementation holds only two members: a pointer to constant CharT and a size.

std::string_view can be thought of as a 'copy by reference' modifying a std::string_view object doesn't
have any effect on the std::string it is viewing.
*/

// STL
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
// TPL
#include <fmt/format.h>

int main()
{
    std::fstream file;

    std::string s1{"red"};
    std::string s2{s1};
    std::string_view v1{s1};

    file.open("8_09.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\n\nfstream open\n\n";

        file << fmt::format("s1: {}\ns2: {}\nv1: {}\n\n", s1, s2, v1);
        file << fmt::format("string_views see changes to the characters they view\n");
        s1.at(0) = 'R';
        file << fmt::format("s1: {}\ns2: {}\nv1: {}\n\n", s1, s2, v1);

        file << fmt::format("string_view can remove a prefix or a suffix from the string it is viewing\n");
        v1.remove_prefix(1);
        v1.remove_suffix(1);
        file << fmt::format("s1: {}\nv1: {}\n\n", s1, v1);

        file << fmt::format("string_view are iterable\n");
        std::string s3{"C-String"};
        std::string_view v3{s3};

        file << "The characters in v3 are: ";
        for (char c : v3)
        {
            file << c << " ";
        }

        file << "\n\nstring_view enable various string operations\n";
        file << fmt::format("v3.size(): {}\n", v3.size());
        file << fmt::format("v3.find('-'): {}\n", v3.find('-'));
        file << fmt::format("v3.starts_with('C'): {}\n", v3.starts_with('C'));
    }

    file.close();
    std::cout << "\n\nfstream closed\n\n";
}
