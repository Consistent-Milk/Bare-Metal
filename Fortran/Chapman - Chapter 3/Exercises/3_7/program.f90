PROGRAM exercise

    ! Author : Mahmudul Hasan
    ! Program Written : 31st December 2022

    IMPLICIT NONE

    REAL :: funxy, x, y

    WRITE(*,*) "Enter values of x and y separated by a space:"
    READ(*,*) x, y


    ! Rewriting the example using nested named if blocks
    OUTER : IF (x >= 0) THEN
          INNER_1 : IF (y >= 0) THEN
                        funxy = x + y
                    ELSE INNER_1
                        funxy = x + y**2
                    END IF INNER_1
            ELSE OUTER
          INNER_2 : IF (y >= 0) THEN
                        funxy = x**2 + y
                    ELSE INNER_2
                        funxy = x**2 + y**2
                    END IF INNER_2
            END IF OUTER

    WRITE(*,*) "The value of function at given point is:", funxy

END PROGRAM
