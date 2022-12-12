#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SALERANGE 11
#define EMPLOYEE 10

int main(void)
{
    int salesRange[SALERANGE] = {0};
    int employeeGrossSales[EMPLOYEE] = {0};
    double salary;
    double commission = 0.09;

    srand(time(NULL));

    // Generate employee gross sales array
    // Upper bound being 10000
    // Highest commision will be 900
    // Lowest salary 0
    // Highest salary 1100
    for (size_t i = 0; i < EMPLOYEE; ++i)
    {
        employeeGrossSales[i] = rand() % 10000;
    }

    for (size_t i = 0; i < EMPLOYEE; ++i)
    {
        salary = 200.0 + employeeGrossSales[i] * commission;
        // we can use only the indices (2-10) as
        // salary/100 produces values between (2-9) for salaries between [200, 1000)
        // to skip writing a switch/if-else block
        if (salary >= 200 && salary < 1000)
        {
            ++salesRange[(int)(salary / 100)];
        }
        else if (salary >= 1000)
        {
            ++salesRange[10];
        }
    }

    for (size_t i = 2; i <= 10; ++i)
    {
        printf("Salary in range salesRange[%zu] = %d\n", i, salesRange[i]);
    }
}