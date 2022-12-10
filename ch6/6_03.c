// todo
// 1. use #define preprocessor directive to define SIZE 5
// 2. declare an int array of SIZE and init with 0 simultaneously
// 3. use 2 + 2 * index to set new values at each index
// 3. pretty print index and value

#include <stdio.h>
#define SIZE 5

int main(void)
{
    // declaring an int array of SIZE(indices 0-4) and initing all index with 0 values
    int array[SIZE] = {0};

    // set new values using the formula
    for (size_t i = 0; i < 5; ++i)
    {
        array[i] = 2 + 2 * i;
    }

    // pretty print
    printf("%s%8s", "Index", "Value");
    puts("");
    for (size_t i = 0; i < 5; ++i)
    { // Note that the 5 in %5zu corresponds to the number of characters in 'Index'
        // Similarly 8 in %8d corresponds to %8s for pretty printing
        printf("%5zu%8d\n", i, array[i]);
    }
}