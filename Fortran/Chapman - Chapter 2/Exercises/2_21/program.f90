PROGRAM distance

    ! Author : Mahmudul Hasan
    ! Program Written : 30th December 2022

    IMPLICIT NONE
    REAL :: x1, y1, x2, y2, d

    WRITE(*,*) "Separate input values using a space."

    WRITE(*,*) "Enter the first point (x1, y1):"
    READ(*,*) x1, y1

    WRITE(*,*) "Enter the second point (x2, y2):"
    READ(*,*) x2, y2

    d = SQRT((x1-x2)**2 + (y1-y2)**2)

    WRITE(*,*) "The distance between the given points is:", d

END PROGRAM distance
