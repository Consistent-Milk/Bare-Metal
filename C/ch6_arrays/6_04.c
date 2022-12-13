// todo
// 1. #define SIZE 5
// 2. init array of SIZE with 1, 2, 3, 4, 5
// 3. sum up array elements
// 4. pretty print result

#include <stdio.h>
#define SIZE 5 // never use ; after #define

int main(void)
{
    int array[SIZE] = {1, 2, 3, 4, 5};

    int sum = 0;
    // always use size_t data type for array index
    for (size_t i = 0; i < SIZE; ++i)
    {
        sum += array[i];
    }

    printf("The sum of the elements of array is %d", sum);
}
