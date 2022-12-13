#include <iostream>

int main()
{
    // initializing variables in declarations
    int passes{0};
    int failures{0};
    int studentCounter{1};

    // process 10 students using counter-controlled loop
    while (studentCounter <= 10)
    {
        // prompt user for input and obtain value from user
        std::cout << "Enter result (1 = pass, 2 = fail): ";
        int result;
        std::cin >> result;

        // if...else is nested in the while statement
        if (result == 1)
        {
            passes = passes + 1;
        }
        else
        {
            failures = failures + 1;
        }

        // increment studentCounter so loop eventually terminates
        studentCounter = studentCounter + 1;
    }

    // termination phase; prepare and display results
    std::cout << "Passed: " << passes << "\nFailed: " << failures << "\n";

    // determine whether more than 8 students passed
    if (passes > 8)
    {
        std::cout << "Bonus to instructor!\n";
    }
}
