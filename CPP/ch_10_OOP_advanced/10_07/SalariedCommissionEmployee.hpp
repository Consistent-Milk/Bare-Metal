#include "SalariedEmployee.hpp"

/**
 * @brief Derived Class <- SalariedEmployee
 * Constructor (1)
 * Private Parameters (2)
 * Setters (2)
 * Getters (4)
 * @param m_grossSales Total sales of an Employee
 * @param m_commissionRate Rate of commission on gross sales for
 * an Employee
 * @param classConstructor_SalariedCommissionEmployee class constructor
 * @param memberFunction_Setter_setGrossSales sets m_grossSales
 * @param memberFunction_Setter_setCommissionRate sets m_commissionRate
 * @param memberFunction_Getter_getGrossSales gets m_grossSales
 * @param memberFunction_Getter_getCommissionRate gets m_commissionRate
 * @param memberFunction_Getter_earnings gets employee earnings with added commission
 * @param memberFunction_FormattedGetter_toString gets formatted representation of class
 */
class SalariedCommissionEmployee : public SalariedEmployee
{
public:
    SalariedCommissionEmployee(std::string_view name, double salary,
                               double grossSales, double commissionRate);

    void setGrossSales(double grossSales);
    double getGrossSales() const;

    void setCommissionRate(double commissionRate);
    double getCommissionRate() const;

    double earnings() const;
    std::string toString() const;

private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};