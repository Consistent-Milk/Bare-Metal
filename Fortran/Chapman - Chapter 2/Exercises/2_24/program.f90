PROGRAM compound_interest

    ! Author : Mahmudul Hasan
    ! Program Written : 30th December 2022

    IMPLICIT NONE
    REAL :: P, APR, F_annual, F_semiannual, F_monthly
    INTEGER, PARAMETER :: m_annual = 1, m_semiannual = 2, m_monthly = 12
    INTEGER :: n

    WRITE(*,*) "Enter the principal amount in account:"
    READ(*,*) P

    WRITE(*,*) "Enter the annual percentage rate:"
    READ(*,*) APR

    WRITE(*,*) "Enter total years(n):"
    READ(*,*) n

    F_annual = P * (1 + APR/(100*m_annual))**(m_annual*n)
    F_semiannual = P * (1 + APR/(100*m_semiannual))**(m_semiannual*n)
    F_monthly = P * (1 + APR/(100*m_monthly))**(m_monthly*n)

    WRITE(*,*) "Future value if compounded annually:", F_annual
    WRITE(*,*) "Future value if compounded semiannually:", F_semiannual
    WRITE(*,*) "Future value if compounded monthly:", F_monthly

END PROGRAM compound_interest
