// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>
// CH
#include "SalariedCommissionEmployee.hpp"

int main()
{
    std::fstream file;

    // instantiate SalariedCommissionEmployee object
    SalariedCommissionEmployee employee{"Bob Lewis", 300.0, 5000.0, .04};

    file.open("Test.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\nfstream open\n";

        // get SalariedCommissionEmployee data
        file << "Employee information obtained by get functions:\n"
             << fmt::format("{}: {}\n{}: {:.2f}\n{}: {:.2f}\n{}: {:.2f}\n",
                            "name", employee.getName(), "salary", employee.getSalary(),
                            "gross sales", employee.getGrossSales(),
                            "commission", employee.getCommissionRate());

        employee.setGrossSales(8000.0);  // change gross sales
        employee.setCommissionRate(0.1); // change commission rate
        file << "\nUpdated employee information from function toString:\n"
             << employee.toString();

        // display the employee's earnings
        file << fmt::format("\nearnings: ${:.2f}\n", employee.earnings());
    }
    else
    {
        std::cout << "File could not be opened!";
    }

    file.close();
    std::cout << "\nfstream closed\n";
}