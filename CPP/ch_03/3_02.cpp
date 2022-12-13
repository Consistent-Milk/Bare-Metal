#include <iostream>
#include <iomanip>

// Algorithm:
// 1. Initialization Phase : Initialize Variables
// 2. Data Processing Phase : Take input from user
// 3. Computation Phase : Compute relevant values
// 4. Termination Phase : Show values as output

// Refined Algorithm
//
// 1. Initialization Phase
// -> For this task we need a 'total' variable to which we will
// add grades one by one. So we initialize it with 0 int value.
// -> We also need a counter variable to count the total number
// of grades input by the user. So we initialize 'gradeCounter'
// with 0 int value.
//
// 2. Data Processing Phase
// -> This program should be sentinel-controlled, i.e., the user
// will be able to input as many data as necessary and the input
// loop will only terminate when the sentinel value is given,
// in this case -1.
//
// 3. Computation Phase
// -> Here we will check the 'gradeCounter' variable first, if
// it is not 0 that will mean that the user has input at least
// one value. Calculate average by using,
// average = total/gradeCounter
//
// 4. Termination Phase
// -> Show the average result and total grades as output
// if any grades given, else show a message indicating no
// grades were given.

int main()
{
    // 1 Initialization Phase
    int total{0};
    int gradeCounter{0};

    // 2 Data Processing Phase
    std::cout << "Enter grade or -1 to quit: ";
    int grade{0};
    std::cin >> grade;

    while (grade != -1)
    {
        total = total + grade;
        gradeCounter = gradeCounter + 1;

        // Promt for input
        std::cout << "Enter grade or -1 to quit: ";
        std::cin >> grade;
    }

    // 3 Computation Phase
    if (gradeCounter != 0)
    {
        double average{static_cast<double>(total) / gradeCounter};

        // 4 Termination phase
        std::cout << "\nTotal of the " << gradeCounter
                  << " grades entered is " << total;
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "\nClass average is " << average << std::endl;
    }
    else
    {
        std::cout << "No grades were entered" << std::endl;
    }
}