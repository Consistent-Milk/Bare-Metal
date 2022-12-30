#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

typedef unsigned long long unll;

unll evenSum = 0;
unll oddSum = 0;

void findEven(unll start, unll end)
{
    for (unll i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            evenSum += i;
        }
    }
}

void findOdd(unll start, unll end)
{
    for (unll i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            oddSum += i;
        }
    }
}

int main()
{
    unll start = 0;
    unll end = 1900000000;

    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    auto stopTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "Odd Sum : " << oddSum << "\n";
    std::cout << "Even Sum : " << evenSum << "\n";
    std::cout << "Sec : " << duration.count() / 1000000 << "\n";

    return 0;
}