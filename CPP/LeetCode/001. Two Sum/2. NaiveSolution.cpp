// STL
#include <iostream>
#include <vector>
// TPL
#include <fmt/format.h>

/*
Input
-----
-> Array of Integers (std::vector<int>)
-> Target Integer (int)

Output
------
-> Array of two integers (std::vector<int>)
*/
std::vector<int> twoSum(std::vector<int> &nums, int target);

int main(void)
{
    std::vector<int> vec{2, 7, 11, 15};
    int target{9};

    std::vector<int> resultVec = twoSum(vec, target);

    for (int &val : resultVec)
    {
        std::cout << fmt::format("{} ", val);
    }
}

/*
This is a brute force approach.
According to the problem statement there is exactly one solution for each case
and the solution can't use the same array element twice to sum up to the target.

Keeping this in mind,
-> We use two for loops and each loop goes through the whole array.
-> Inside the inner for loop we use an if statement to terminate the
loop if we have found of two array elements with different indices
that sum up to the target and return the indices in std::vector<int> form.
*/
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            int s = nums[i] + nums[j];
            if (s == target && i != j)
            {
                return std::vector<int>{i, j};
            }
        }
    }
    return std::vector<int>{-1, -1};
}

// int main()
// {
//     constexpr int size = 4;

//     std::vector<int> vec_1(size);
//     int target{0};

//     // Reading from file
//     // --------------------------------------------------------
//     std::fstream inputfile("Sample.txt", std::ios::in);

//     if (inputfile.is_open())
//     {
//         for (size_t i = 0; i < size; ++i)
//         {
//             inputfile >> vec_1[i];
//         }

//         inputfile >> target;

//         inputfile.close();

//         for (int &val : vec_1)
//         {
//             std::cout << fmt::format("{} ", val);
//         }

//         std::cout << target << std::endl;
//     }
//     else
//     {
//         std::cout << "Error opening file";
//     }

//     std::vector<int> answer = twoSum(vec_1, target);

//     for (int &val : answer)
//     {
//         std::cout << fmt::format("{} ", val);
//     }
//     // --------------------------------------------------------
// }