#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int binarySearch(const int b[], int key, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);
void bubbleSort(int b[]);

int main(void)
{
    puts("");

    // Seed PRNG with time library
    srand(time(NULL));

    int a[SIZE] = {0};
    // Create Data
    for (size_t i = 0; i < SIZE; ++i)
    {
        a[i] = 1 + rand() % 100;
    }

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");

    bubbleSort(a);

    printf("%s", "Enter a number between 1 and 100: ");
    int key = 0;
    scanf("%d", &key);

    printHeader();

    int result = binarySearch(a, key, 0, SIZE - 1);

    // Display Results
    if (result != -1)
    {
        printf("\n%d found at index %d of the array\n", key, result);
    }
    else
    {
        printf("\n%d not found in array\n", key);
    }
}

void bubbleSort(int b[])
{
    // Loop to control the number of passes
    for (int pass = 1; pass < SIZE; ++pass)
    {
        for (size_t j = 0; j < SIZE - 1; ++j)
        {
            if (b[j] > b[j + 1])
            {
                int hold = b[j];
                b[j] = b[j + 1];
                b[j + 1] = hold;
            }
        }
    }
}

// We use const to tell the compiler that we don't want to modify
// the array inside this function
int binarySearch(const int b[], int key, size_t low, size_t high)
{

    while (low <= high)
    {
        // Integer arithmetic takes care of the rounding problem here
        size_t middle = (low + high) / 2;
        printRow(b, low, middle, high);
        if (key == b[middle])
        {
            return middle;
        }
        else if (key < b[middle])
        { // key is in the left subarray
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return -1;
}

void printHeader(void)
{
    puts("\nSubscripts");

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%4d ", i);
    }

    puts("");

    for (int i = 1; i <= 4; ++i)
    {
        printf("%s", "-");
    }

    puts("");
}

void printRow(const int b[], size_t low, size_t mid, size_t high)
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        if (i < low || i > high)
        {
            printf("%s", "     ");
        }
        else if (i == mid)
        {
            printf("%4d*", b[i]);
        }
        else
        {
            printf("%5d", b[i]);
        }
    }

    puts("");
}