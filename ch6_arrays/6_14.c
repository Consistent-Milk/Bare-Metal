#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int linearSearch(const int a[], int key, size_t size);
void printArray(const int a[]);

int main(void)
{
    puts("");
    // Seed PRNG
    srand(time(NULL));

    int a[SIZE] = {0};

    for (size_t x = 0; x < SIZE; ++x)
    {
        a[x] = 1 + rand() % 500;
    }

    puts("The elements of the array are:");
    printArray(a);
    puts("\n");
    printf("Enter integer search key: ");

    int searchKey = 0;
    scanf("%d", &searchKey);
    puts("");

    // Use linear search to find index of key in array if exists
    int subscript = linearSearch(a, searchKey, SIZE);

    if (subscript != -1)
    {
        printf("Found value at subscript %d\n", subscript);
    }
    else
    {
        puts("Value not found");
    }

    puts("");
}

// Implement Linear Search
int linearSearch(const int a[], int key, size_t size)
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        if (a[i] == key)
        {
            return i;
        }
    }

    return -1;
}

void printArray(const int a[])
{
    // output array contents
    for (size_t j = 0; j < SIZE; ++j)
    {

        if (j % 20 == 0)
        { // begin new line every 20 values
            puts("");
        }

        printf("%4d", a[j]);
    }
}