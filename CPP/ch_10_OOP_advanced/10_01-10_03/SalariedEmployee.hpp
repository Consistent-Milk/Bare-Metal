#pragma once
// STL
#include <string>
#include <string_view>

class SalariedEmployee
{
public:
    SalariedEmployee(std::string_view name, double salary);

    void setName(std::string_view name);
    std::string getName() const;

    void setSalary(double salary);
    double getSalary() const;

    double earnings() const;
    std::string toString() const;

private:
    std::string m_name{};
    double m_salary{0.0};
};