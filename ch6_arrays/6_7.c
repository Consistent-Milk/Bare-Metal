#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

int main(void)
{
    srand(time(NULL));

    int frequency[SIZE] = {0};

    for (int roll = 1; roll <= 600000000; ++roll)
    {
        size_t face = 1 + rand() % 6;
        ++frequency[face];
    }

    printf("%s%17s\n", "Face", "Frequency");

    for (size_t face = 1; face < SIZE; ++face)
    {
        printf("%4zu%17d\n", face, frequency[face]);
    }
}