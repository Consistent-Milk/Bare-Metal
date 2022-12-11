#include <stdio.h>
#define SIZE 99

void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void bubbleSort(int a[]);
void printArray(const int a[]);

int main(void)
{
    int frequency[10] = {0};

    int response[SIZE] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
                          7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
                          6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
                          7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
                          6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
                          7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
                          5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
                          7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
                          7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
                          4, 5, 6, 1, 6, 5, 7, 8, 7};

    mean(response);
    median(response);
    mode(frequency, response);
}

void mean(const int answer[])
{
    printf("%s\n%s\n%s\n", "--------", " Mean", "--------");

    int total = 0;

    for (size_t j = 0; j < SIZE; ++j)
    {
        total += answer[j];
    }

    printf("The mean is the average value of the data\n"
           "items. The mean is equal to the total of\n"
           "all the data items divided by the number\n"
           "of data items (%u). The mean value for\n"
           "this run is: %u / %u = %.4f\n\n",
           SIZE, total, SIZE, (double)total / SIZE);
}

void median(int answer[])
{
    printf("\n%s\n%s\n%s\n%s", "--------", " Median", "--------",
           "The unsorted array of responses is");

    printArray(answer);

    bubbleSort(answer);
    printf("%s", "\n\nThe sorted array is");
    printArray(answer); // output sorted array

    printf("\n\nThe median is element %u of\n"
           "the sorted %u element array.\n"
           "For this run the median is %u\n\n",
           SIZE / 2, SIZE, answer[SIZE / 2]);
}

void mode(int freq[], const int answer[])
{
    printf("\n%s\n%s\n%s\n", "--------", " Mode", "--------");

    // initialize frequencies to 0
    for (size_t rating = 1; rating <= 9; ++rating)
    {
        freq[rating] = 0;
    }

    // summarize frequencies
    for (size_t j = 0; j < SIZE; ++j)
    {
        ++freq[answer[j]];
    }

    // output headers for result columns
    printf("%s%11s%19s\n\n%54s\n%54s\n\n",
           "Response", "Frequency", "Bar Chart",
           "1 1 2 2", "5 0 5 0 5");

    // output results
    int largest = 0;   // represents largest frequency
    int modeValue = 0; // represents most frequent response

    for (size_t rating = 1; rating <= 9; ++rating)
    {
        printf("%8zu%11d ", rating, freq[rating]);
        // keep track of mode value and largest frequency value
        if (freq[rating] > largest)
        {
            largest = freq[rating];
            modeValue = rating;
        }

        // output bar representing frequency value
        for (int h = 1; h <= freq[rating]; ++h)
        {
            printf("%s", "*");
        }

        puts(""); // being new line of output
    }

    // display the mode value
    printf("\nThe mode is the most frequent value.\n"
           "For this run the mode is %d which occurred %d times.\n",
           modeValue, largest);
}

void bubbleSort(int a[])
{
    // Loop to control the number of passes
    for (int pass = 1; pass < SIZE; ++pass)
    {
        for (size_t j = 0; j < SIZE - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

// output array contents (20 values per row)
void printArray(const int a[])
{
    // output array contents
    for (size_t j = 0; j < SIZE; ++j)
    {

        if (j % 20 == 0)
        { // begin new line every 20 values
            puts("");
        }

        printf("%2d", a[j]);
    }
}