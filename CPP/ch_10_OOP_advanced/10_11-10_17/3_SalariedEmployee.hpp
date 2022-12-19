#pragma once
#include "1_Employee.hpp"

class SalariedEmployee final : public Employee
{
private:
    double m_salary{0.0};

public:
    void setSalary(double salary);

    double getSalary() const;
    double earnings() const override;
    std::string toString() const override;

    SalariedEmployee(std::string_view name, double salary);
    virtual ~SalariedEmployee() = default;
};