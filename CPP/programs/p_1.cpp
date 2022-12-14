// Author : Awnon Bhowmik
#include <iostream>
#include <chrono>
#include "bignumber.h"

using namespace std;
using namespace chrono;

BigNumber recur_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recur_fib(n - 1) + recur_fib(n - 2);
    }
}

BigNumber iter_fib(int n)
{
    BigNumber a = 0, b = 1;
    BigNumber c = 0;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    cout << "\n\nTerm\tIterative\t\t\t\tTime\n";
    // auto t1 = high_resolution_clock::now();
    // BigNumber fib1 = recur_fib(35);
    // auto t2 = high_resolution_clock::now();
    // duration<double, milli> diff1 = t2 - t1;

    auto t1 = high_resolution_clock::now();
    BigNumber fib2 = iter_fib(1000);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> diff2 = t2 - t1;

    // cout << 35 << "\t" << fib1 << "\t\t" << diff1.count() << "\t\t" << fib2 << "\t\t" << diff2.count() << "\n";
    cout << 1000 << "\t" << fib2 << "\t\t" << diff2.count() << "\n\n\n";
    return 0;
}