PROGRAM exercise

    ! Author : Mahmudul Hasan
    ! Program Written : 30th December 2022

    ! Improve after later chapters: Loops, Formatted Output

    IMPLICIT NONE

    REAL :: weight, fee, temp
    REAL, PARAMETER :: baseFee = 15.0, baseWeight = 2.0, excessCharge = 15.0

    WRITE(*,*) "Enter the weight of the package:"
    READ(*,*) weight

    ! Stop the program if a weight of 0 or negative value is given
    ! Later improve this using while loop until the user inputs a valid value
    IF (weight <= 0) THEN
        WRITE(*,*) "Weight must have a positive value."
        STOP
    END IF

    IF (weight < 2.0) THEN
        fee = baseFee
    ELSE IF (weight < 70.0) THEN
        temp = weight - baseWeight
        fee = baseFee + CEILING(temp) * 5.0 ! e.g., if a weight of 64.4 is given, charge for 65 pounds
    ELSE IF (weight <= 100.0) THEN
        temp = weight - baseWeight
        fee = baseFee + CEILING(temp) * 5.0 + excessCharge
    ELSE
        WRITE(*,*) "Package exceeding 100 pounds will not be accepted."
        STOP
    END IF

    WRITE(*,*) "Weight of", weight, "pounds will cost", fee

END PROGRAM exercise
