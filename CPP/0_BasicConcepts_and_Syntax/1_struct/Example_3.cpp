#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
structs can be thought of as an user defined combined data type
of intrinsic data types. Thus it can act as a data type itself and
can be passed on to functions as parameters.
*/

// struct Definition
struct Person
{
    int citizenship;
    int age;
};

// Function Prototype
void func(struct Person p);

int main()
{
    // Create an instance of struct Person
    struct Person p;

    // Access and set values to its members
    p.citizenship = 1;
    p.age = 27;

    // Pass the struct Person as a parameter to a function
    func(p);

    return 0;
}

// This function basically prints out the values of the members of the struct
void func(struct Person p)
{
    cout << " Person citizenship: " << p.citizenship << endl;
    cout << " Person age: " << p.age;
}