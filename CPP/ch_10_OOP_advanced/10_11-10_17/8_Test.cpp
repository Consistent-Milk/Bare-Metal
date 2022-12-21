#include "1_Employee.hpp"
#include "3_SalariedEmployee.hpp"
#include "5_CommissionEmployee.hpp"

void virtualViaPointer(const Employee *baseCLassPtr);
void virtualViaReference(const Employee &baseClassRef);

int main(void)
{
    SalariedEmployee salaried{"John Doe", 800.0};
    CommissionEmployee cmmissioned{"Jane Doe", 10000, .06};

    //
}