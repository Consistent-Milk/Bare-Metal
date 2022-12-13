#include <iostream>

void useLocal();       // function prototype
void useStaticLocal(); // function prototype
void useGlobal();      // function prototype

int x{1}; // global variable

int main()
{
    std::cout << "global x in main is " << x << '\n';

    const int x{5}; // local variable to main

    std::cout << "local x in main's outer scope is " << x << '\n';

    {                   // block starts a new scope
        const int x{7}; // hides both x in outer scope and global x

        std::cout << "local x in main's inner scope is " << x << '\n';
    }

    std::cout << "local x in main's outer scope is " << x << '\n';

    useLocal();       // useLocal has local x
    useStaticLocal(); // useStaticLocal has static local x
    useGlobal();      // useGlobal uses global x
    useLocal();       // useLocal reinitializes its local x
    useStaticLocal(); // static local x retains its prior value
    useGlobal();      // global x also retains its prior value

    std::cout << "\nlocal x in main is " << x << '\n';
}

// useLocal reinitializes local variable x during each call
void useLocal()
{
    int x{25}; // initialized each time useLocal is called

    std::cout << "\nlocal x is " << x << " on entering useLocal\n";
    ++x;
    std::cout << "local x is " << x << " on exiting useLocal\n";
}

// useStaticLocal initializes static local variable x only the
// first time the function is called; value of x is saved
// between calls to this function
void useStaticLocal()
{
    static int x{50}; // initialized first time useStaticLocal is called

    std::cout << "\nlocal static x is " << x
              << " on entering useStaticLocal\n";
    ++x;
    std::cout << "local static x is " << x << " on exiting useStaticLocal\n";
}

// useGlobal modifies global variable x during each call
void useGlobal()
{
    std::cout << "\nglobal x is " << x << " on entering useGlobal\n";
    x *= 10;
    std::cout << "global x is " << x << " on exiting useGlobal\n";
}
