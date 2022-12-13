#include <stdio.h>
#define SIZE 5

void modifyArray(int b[], size_t size);
void modifyElement(int e);

int main(void)
{
    int a[SIZE] = {0, 1, 2, 3, 4};

    puts("Original array:");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%3d", a[i]);
    }

    puts("");

    modifyArray(a, SIZE);

    puts("The values of the modified array are:");

    // Output modiefied array
    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%3d", a[i]);
    }

    printf("\nThe value of a[3] is %d\n", a[3]);

    modifyElement(a[3]);

    printf("The value of a[3] after being passed to modifyElements is %d", a[3]);
}

void modifyArray(int b[], size_t size)
{ // In function b[] actually points to the array a[] in memory
    for (size_t i = 0; i < SIZE; ++i)
    { // This actually modifies the array a[]
        b[i] *= 2;
    }
}

void modifyElement(int e)
{
    e *= 2;
    printf("The value of a[3] inside modifyElement is %d\n", e);
}