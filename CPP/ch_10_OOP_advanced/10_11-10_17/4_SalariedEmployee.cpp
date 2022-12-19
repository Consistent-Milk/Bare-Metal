#include "3_SalariedEmployee.hpp"

SalariedEmployee::SalariedEmployee(std::string_view name, double salary)
    : Employee{name}
{
    setSalary(salary);
}

void SalariedEmployee::setSalary(double salary)
{
    if (salary < 0.0)
    {
        throw std::invalid_argument("Weekly salary must be >= 0.0");
    }

    m_salary = salary;
}

// return salary
double SalariedEmployee::getSalary() const { return m_salary; }

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const { return getSalary(); }

// return a string representation of SalariedEmployee
std::string SalariedEmployee::toString() const
{
    return fmt::format("{}\n{}: ${:.2f}", Employee::toString(),
                       "salary", getSalary());
}