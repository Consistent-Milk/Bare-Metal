// STL
#include <iostream>
#include <vector>
#include <unordered_map>
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

Here we use the STL implementation of an unordered_map.

Unordered map is an associative container that contains
key-value pairs with unique keys. Search, insertion,
and removal of elements have average constant-time complexity.

Internally, the elements are not sorted in any particular order,
but organized into buckets. Which bucket an element is
placed into depends entirely on the hash of its key.
Keys with the same hash code appear in the same bucket.
This allows fast access to individual elements,
since once the hash is computed, it refers to the
exact bucket the element is placed into.

The member functions used are:
# size()
---------
UseDomain -> Capacity
Access -> public member function
Output -> Returns the number of elements (public member function)

# count()
---------
UseDomain -> Lookup
Access -> public member function
Output -> Returns the number of elements matching specific key

Approach:
---------
1. Declare an unordered_map
2. Loop through the input vector
3. Store (key, value) of unordered map as
(key: array element, value: array element index)
4. If map.count(target - array[index]) returns non zero value,
i.e., there exists a key such that, key + array[index] = target,
terminate the loop and return [key, index].
*/
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
        // The condition is true only if map.count(target - nums[i]) != 0
        if (map.count(target - nums[i]))
        {
            return std::vector<int>{map[target - nums[i]], i};
        }
        map[nums[i]] = i;
    }

    return std::vector<int>{-1, -1};
}