#pragma once
#include "1_Employee.hpp" // Employee class definition

class CommissionEmployee final : public Employee
{
public:
    CommissionEmployee(std::string_view name, double grossSales,
                       double commissionRate);
    virtual ~CommissionEmployee() = default; // virtual destructor

    void setGrossSales(double grossSales);
    double getGrossSales() const;

    void setCommissionRate(double commissionRate);
    double getCommissionRate() const;

    // keyword override signals intent to override
    double earnings() const override;      // calculate earnings
    std::string toString() const override; // string representation
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};
