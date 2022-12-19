#include "1_Employee.hpp"

// constructor
Employee::Employee(std::string_view name) : m_name{name} {} // empty body

// set name
void Employee::setName(std::string_view name) { m_name = name; }

// get name
std::string Employee::getName() const { return m_name; }

// return string representation of an Employee
std::string Employee::toString() const
{
    return fmt::format("name: {}", getName());
}