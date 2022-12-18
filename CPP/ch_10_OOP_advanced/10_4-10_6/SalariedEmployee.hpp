#pragma once
// STL
#include <string>
#include <string_view>

class SalariedEmployee
{
public:
    // Constructors
    SalariedEmployee(std::string_view name, double salary);

    // Setters
    void setName(std::string_view name);
    void setSalary(double salary);

    // Getters
    std::string getName() const;
    double getSalary() const;
    double earnings() const;

    // Formatted Getters
    std::string toString() const;

private:
    std::string m_name{};
    double m_salary{0.0};
};