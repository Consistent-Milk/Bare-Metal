#include <iostream>
#include <string>
#include <fstream>
#define FMT_HEADER_ONLY
#include <fmt/format.h>

/*
This example shows how to define, initialize, access members and set member values of a struct.
*/

struct PersonGarbage
{
    int age;
    std::string name; // std::string is always initialized as an empty string.
};

struct Person
{
    // I think initializing members is a good practice instead of having garbage values
    int age{0};
    std::string name{"Person"};
};

int main(void)
{
    std::fstream file;

    file.open("Example_1.txt", std::ios::out);

    PersonGarbage p1;
    Person p2;

    if (file.is_open())
    {
        file << fmt::format("Accessing default values of PersonGarbage and Person:\n\n");
        file << fmt::format("PersonGarbage p1\nage: {}\nname: {}\n\n", p1.age, p1.name);
        file << fmt::format("Person p2\nage: {}\nname: {}\n", p2.age, p2.name);

        file << fmt::format("\nSetting new values to all members of p1 and p2\n\n");

        // Setting new values by combining dot(.) and assignment(=) operators
        p1.age = 20;
        p1.name = "John Doe";
        p2.age = 20;
        p2.name = "Jane Doe";

        file << fmt::format("Accessing new values of PersonGarbage and Person:\n\n");
        file << fmt::format("PersonGarbage p1\nage: {}\nname: {}\n\n", p1.age, p1.name);
        file << fmt::format("Person p2\nage: {}\nname: {}\n", p2.age, p2.name);
    }
    else
    {
        std::cout << "File could not be opened, exiting program...";
        return 0;
    }

    file.close();
    return 0;
}