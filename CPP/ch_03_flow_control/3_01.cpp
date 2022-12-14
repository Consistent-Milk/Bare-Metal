// Solving class-average problem using
// counter controlled iteration

#include <iostream>

int main()
{
    // Initializing variables
    int total{0};
    int gradeCounter{1};

    std::cout << "Enter total number of students: ";
    int students{0};
    std::cin >> students;

    while (gradeCounter <= students)
    {
        std::cout << "\nEnter Grade: ";

        int grade{0};
        std::cin >> grade;

        total = total + grade;
        gradeCounter = gradeCounter + 1;
    }

    int average{total / students};

    std::cout << "\nTotal of all " << students << "grades is " << total;
    std::cout << "\nClass average is " << average << std::endl;
}