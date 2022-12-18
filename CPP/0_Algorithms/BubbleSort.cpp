// STL
#include <iostream>
#include <random>
#include <vector>
// TPL
#define FMT_HEADER_ONLY
#include <fmt/format.h>

// function prototype
void bubbleSort(std::vector<int> &b);

int main(void)
{
    constexpr int vecSize{10};

    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution prng{1, 100};

    std::vector<int> a(vecSize);

    // Populate array with random values between (1-100)
    for (int &val : a)
    {
        val = prng(engine);
    }

    std::cout << fmt::format("Unmodified Vector: ");
    for (int &val : a)
    {
        std::cout << fmt::format("{} ", val);
    }

    bubbleSort(a);

    std::cout << fmt::format("\nArray after bubbleSort:\n");
    for (int &val : a)
    {
        std::cout << fmt::format("{} ", val);
    }

    std::cout << "\n";
}

void bubbleSort(std::vector<int> &b)
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
    for (size_t pass = 1; pass < b.size(); ++pass)
    {
        int swap = 0;
        for (size_t j = 0; j < b.size() - pass; ++j)
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
        std::cout << fmt::format("\nArray after Pass {}:\n", pass);
        for (size_t i = 0; i < b.size(); ++i)
        {
            std::cout << fmt::format("{} ", b[i]);
        }
        std::cout << "\n";
        // unnecessary

        if (swap == 0)
        {
            break;
        }
    }
}