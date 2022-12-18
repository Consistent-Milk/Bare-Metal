#pragma once
// STL
#include <string>
#include <string_view>

/*
class MethodCounts
------------------
Constructor (1)
Setters (2)
Getters (4)
*/
class SalariedEmployee
{
public:
    SalariedEmployee(std::string_view, double salary);

    // Setters
    // Validation : False
    void setName(std::string_view name);
    // Validation : True
    void setSalary(double salary);

    // Getters
    std::string getName() const;
    double getSalary() const;
    double earnings() const;
    std::string toString() const;

private:
    std::string m_name{};
    double m_salary{0.0};
};