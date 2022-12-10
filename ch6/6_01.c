#include <stdio.h>

// todo
// 1. declare an int array of size 5
// 2. init array with all 0
// 3. pretty print index and value

int main(void)
{
    // declaring an int array of size 5(indices 0-4)
    int array[5];

    // init with zero values
    for (size_t i = 0; i < 5; ++i)
    {
        array[i] = 0;
    }

    // pretty print
    printf("%s%8s", "Index", "Value");
    puts("");
    for (size_t i = 0; i < 5; ++i)
    {
        printf("%5zu%8d\n", i, array[i]);
    }
}