#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int *const array, size_t size);

int main(void)
{
    puts("");

    srand(time(NULL));

    int a[SIZE] = {0};

    for (size_t i = 0; i < SIZE; ++i)
    {
        a[i] = 1 + rand() % 100;
    }

    puts("Data items in original order:");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    bubbleSort(a, SIZE);

    puts("\nData items in ascending order:");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");
}

void bubbleSort(int *const array, size_t size)
{
    // Function Prototype
    void swap(int *elementPtr, int *element2Ptr);
}