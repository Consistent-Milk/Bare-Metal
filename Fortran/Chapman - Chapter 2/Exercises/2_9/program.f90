PROGRAM triangle
    IMPLICIT NONE

    REAL, PARAMETER :: PI = 3.1416
    REAL :: a, b, c, theta, radian_conversion, v_c

    WRITE (*,*) 'Enter the length of the hypotenuse C:'
    READ (*,*) c
    WRITE (*,*) 'Enter the angle THETA in degrees:'
    READ (*,*) theta

    ! COS and SIN intrinsic functions expects inputs in radians

    radian_conversion = PI / 180.0

    a = c * COS ( theta * radian_conversion )
    b = c * SIN ( theta * radian_conversion )

    WRITE (*,*) 'The length of the adjacent side is ', a
    WRITE (*,*) 'The length of the opposite side is ', b

    ! Verify result using Pythagoras Theorem

    v_c = SQRT(a**2 + b**2)

    WRITE(*,*) "The hypotenuse from computed sides is: ", v_c

END PROGRAM triangle
