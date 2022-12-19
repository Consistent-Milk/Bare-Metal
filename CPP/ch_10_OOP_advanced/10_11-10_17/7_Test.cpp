#include "1_Employee.hpp"
#include "3_SalariedEmployee.hpp"
#include "5_CommissionEmployee.hpp"

void virtualViaPointer(const Employee *baseClassPtr);   // prototype
void virtualViaReference(const Employee &baseClassRef); // prototype

int main()
{
    // create derived-class objects
    SalariedEmployee salaried{"John Smith", 800.0};
    CommissionEmployee commission{"Sue Jones", 10000, .06};

    // output each Employee
    std::cout << "EMPLOYEES PROCESSED INDIVIDUALLY VIA VARIABLE NAMES\n"
              << fmt::format("{}\n{}{:.2f}\n\n{}\n{}{:.2f}\n\n",
                             salaried.toString(), "earned $", salaried.earnings(),
                             commission.toString(), "earned $", commission.earnings());

    // create and initialize vector of base-class pointers
    std::vector<Employee *> employees{&salaried, &commission};

    std::cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA"
              << " DYNAMIC BINDING\n\n";

    // call virtualViaPointer to print each Employee
    // and earnings using dynamic binding
    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS POINTERS\n";

    for (const Employee *employeePtr : employees)
    {
        virtualViaPointer(employeePtr);
    }

    // call virtualViaReference to print each Employee
    // and earnings using dynamic binding
    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS REFERENCES\n";

    for (const Employee *employeePtr : employees)
    {
        virtualViaReference(*employeePtr); // note dereferenced pointer
    }
}

// call Employee virtual functions toString and earnings via a
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee *baseClassPtr)
{
    std::cout << fmt::format("{}\nearned ${:.2f}\n\n",
                             baseClassPtr->toString(), baseClassPtr->earnings());
}

// call Employee virtual functions toString and earnings via a
// base-class reference using dynamic binding
void virtualViaReference(const Employee &baseClassRef)
{
    std::cout << fmt::format("{}\nearned ${:.2f}\n\n",
                             baseClassRef.toString(), baseClassRef.earnings());
}