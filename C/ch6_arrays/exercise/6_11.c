#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// function prototype
void bubbleSort(int b[]);

int main(void)
{
    int a[SIZE] = {0};

    // Seed PRNG with time
    srand(time(NULL));

    // Populate array with random values between (1-100)
    for (size_t i = 0; i < SIZE; ++i)
    {
        a[i] = 1 + rand() % 100;
    }

    puts("");
    puts("Unmodified array:");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");
    bubbleSort(a);

    puts("\nArray after bubbleSort:");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("\n");
}

void bubbleSort(int b[])
{
    // Algorithm
    // 1 -> Start from first index
    // 2 -> If a value assigned to an index
    // is greater than the value in next index
    // use a temp variable to store the value
    // 3 -> Swap array[index + 1] with array[index]
    // 4 -> Assign temp value to array[index + 1]

    // Improved Algorithm
    // 1 -> After the a pass the largest element
    // will always be in the last index, and so on.
    // Thus we do not need to access last indices
    // after a pass. So each pass should only
    // access unsorted indices. Reducing total
    // array access significantly.
    // 2 -> If no swaps have been made in a pass
    // that implies that the array is already sorted
    // and no further passes are necessary, so we should
    // break out of the loop and terminate the
    // algorithm.

    // Intuition: The algorithm basically 'bubbles up'
    // higher values to higher indices and pushes down
    // lower values to lower indices
    for (int pass = 1; pass < SIZE; ++pass)
    {
        int swap = 0;
        for (size_t j = 0; j < SIZE - pass; ++j)
        {
            if (b[j] > b[j + 1])
            {
                int hold = b[j];
                b[j] = b[j + 1];
                b[j + 1] = hold;
                swap += 1;
            }
        }

        // unnecessary - Only for visualization
        printf("\nArray after Pass %d:\n", pass);
        for (size_t i = 0; i < SIZE; ++i)
        {
            printf("%4d", b[i]);
        }
        puts("");
        // unnecessary

        if (swap == 0)
        {
            break;
        }
    }
}