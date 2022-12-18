// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>
// CH
#include "SalariedEmployee.hpp" // SalariedEmployee class definition

int main()
{
    std::fstream file;
    // instantiate a SalariedEmployee object
    SalariedEmployee employee{"Sue Jones", 300.0};

    file.open("Test.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\nfstream open\n";
        file << "Get SalariedEmployee data\n";
        file << "Employee information obtained by get functions:\n"
             << fmt::format("Name: {}\nSalary: ${:.2f}\n", employee.getName(),
                            employee.getSalary());

        employee.setSalary(500.0); // change salary
        file << "\nUpdated employee information from function toString:\n"
             << employee.toString();

        // display only the employee's earnings
        file << fmt::format("\nEarnings: ${:.2f}\n", employee.earnings());
    }

    file.close();
    std::cout << "\nfstream closed\n";
}