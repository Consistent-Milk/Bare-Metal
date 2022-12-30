PROGRAM total_pay
    
    ! Author : Mahmudul Hasan
    ! Program Written : 30th December 2022

    IMPLICIT NONE

    INTEGER :: hoursWorked
    REAL :: hourlyPayRate, totalPay

    WRITE(*,*) "Enter hourly pay rate and hours worked separated by a space: "
    READ(*,*) hourlyPayRate, hoursWorked

    totalPay = hourlyPayRate * hoursWorked

    WRITE(*,*) "Total Salary of the employee is:", totalPay

END PROGRAM
