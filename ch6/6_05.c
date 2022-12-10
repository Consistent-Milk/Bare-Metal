#include <stdio.h>
#define RESPONSES_SIZE 20
#define FREQUENCY_SIZE 6

int main(void)
{
    int responses[RESPONSES_SIZE] = {1, 2, 13, 5, 4, 3, 5, 65, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2};

    int frequency[FREQUENCY_SIZE] = {0};

    // Implement bounds checking as responses[answer] might have values
    // outside the array bound 0 - 5
    for (size_t answer = 0; answer < RESPONSES_SIZE; ++answer)
    {
        int boundCheck = responses[answer];

        if (boundCheck > 5 || boundCheck < 0)
        {
            printf("Invalid value (%d) found for frequency array. Such a response should not exist in responses array.\n", boundCheck);
            continue;
        }
        else
        { // Add valid response to frequency array.
            ++frequency[boundCheck];
        }
    }

    printf("%s%12s\n", "Rating", "Frequency");

    for (size_t rating = 1; rating < FREQUENCY_SIZE; ++rating)
    {
        printf("%6zu%12d\n", rating, frequency[rating]);
    }
}