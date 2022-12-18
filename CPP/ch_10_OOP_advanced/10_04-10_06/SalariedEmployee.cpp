// STL
#include <stdexcept>
// TPL
#define FMT_HEADER_ONLY
#include <fmt/format.h>
// CH
#include "SalariedEmployee.hpp"

using namespace fmt;

// Constructor Definition
SalariedEmployee::SalariedEmployee(std::string_view name, double salary)
    : m_name{name}
{
    setSalary(salary);
}

// Setters
void SalariedEmployee::setName(std::string_view name)
{
    m_name = name;
}

void SalariedEmployee::setSalary(double salary)
{
    if (salary < 0.0)
    {
        throw std::invalid_argument("Salary must be >= 0.0");
    }
    m_salary = salary;
}

// Getters
std::string SalariedEmployee::getName() const
{
    return m_name;
}

double SalariedEmployee::getSalary() const
{
    return m_salary;
}

double SalariedEmployee::earnings() const
{
    return getSalary();
}

// Formatted Getters
std::string SalariedEmployee::toString() const
{
    return fmt::format("Name: {}\nSalary: ${:.2f}\n", getName(), getSalary());
}