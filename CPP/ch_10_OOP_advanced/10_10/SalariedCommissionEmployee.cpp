#include "SalariedCommissionEmployee.hpp"

SalariedCommissionEmployee::SalariedCommissionEmployee(
    std::string_view name, double salary, double grossSales,
    double commissionRate) : SalariedEmployee{name, salary}
{
    setGrossSales(grossSales);
    setCommissionRate(commissionRate);
}

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
        throw std::invalid_argument(
            "Commission rate must be > 0.0 and < 1.0");
    }

    m_commissionRate = commissionRate;
}

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
    return SalariedEmployee::earnings() +
           getGrossSales() * getCommissionRate();
}

std::string SalariedCommissionEmployee::toString() const
{
    return fmt::format(
        "{}gross sales: ${:.2f}\ncommission rate: {:.2f}\n",
        SalariedEmployee::toString(), getGrossSales(), getCommissionRate());
}