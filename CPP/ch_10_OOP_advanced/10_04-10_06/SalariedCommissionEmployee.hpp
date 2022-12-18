#pragma once
// STL
#include <string>
#include <string_view>
#include "SalariedEmployee.hpp"

// Derived Class
class SalariedCommissionEmployee : public SalariedEmployee
{
public:
    SalariedCommissionEmployee(std::string_view name, double salary, double grossSales, double commissionRate);

    // Setters
    void setGrossSales(double grossSales);
    void setCommissionRate(double commissionRate);

    // Getters
    double getGrossSales() const;
    double getCommissionRate() const;
    double earnings() const;

    // Formatted Getters
    std::string toString() const;

private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};