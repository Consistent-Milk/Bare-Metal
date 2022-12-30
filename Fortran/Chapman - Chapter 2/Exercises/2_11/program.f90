PROGRAM total_pay

    IMPLICIT NONE

    INTEGER :: hoursWorked
    REAL :: hourlyPayRate, totalPay

    WRITE(*,*) "Enter hourly pay rate and hours worked separated by a space: "
    READ(*,*) hourlyPayRate, hoursWorked

    totalPay = hourlyPayRate * hoursWorked

    WRITE(*,*) "Total Salary of the employee is:", totalPay

END PROGRAM
