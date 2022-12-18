// STL
#include <stdexcept>
// TPL
#include <fmt/format.h>
// CH
#include "SalariedCommissionEmployee.hpp"

// Constructor
SalariedCommissionEmployee::SalariedCommissionEmployee(std::string_view name, double salary, double grossSales, double commissionRate)
    : SalariedEmployee{name, salary}
{
    // Validate and set
    setGrossSales(grossSales);
    setCommissionRate(commissionRate);
}

// Setters
void SalariedCommissionEmployee::setGrossSales(double grossSales)
{
    if (grossSales < 0.0)
    {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }

    m_grossSales = grossSales;
}

void SalariedCommissionEmployee::setCommissionRate(double commissionRate)
{
    if (commissionRate <= 0.0 || commissionRate >= 1.0)
    {
        throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }

    m_commissionRate = commissionRate;
}

// Getters
double SalariedCommissionEmployee::getGrossSales() const
{
    return m_grossSales;
}

double SalariedCommissionEmployee::getCommissionRate() const
{
    return m_commissionRate;
}

double SalariedCommissionEmployee::earnings() const
{
    return SalariedEmployee::earnings() + getGrossSales() * getCommissionRate();
}

// Formatted Getters
std::string SalariedCommissionEmployee::toString() const
{
    return fmt::format(
        "{}Gross Sales: ${:.2f}\nCommission Rate: {:.2f}\n",
        SalariedEmployee::toString(), getGrossSales(), getCommissionRate());
}