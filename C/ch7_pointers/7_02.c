#include <stdio.h>

int cubeByValue(int n);

int main(void)
{
    int number = 5;

    printf("The original value of number is %d", number);
    number = cubeByValue(number);
    printf("\nThe new value of number is %d\n", number);
}

int cubeByValue(int n)
{
    return n * n * n;
}