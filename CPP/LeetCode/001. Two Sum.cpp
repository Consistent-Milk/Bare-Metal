#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.count(target - nums[i]))
            {
                return std::vector<int>{map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }

        return std::vector<int>{-1, -1};
    }
};

// Runtime
// 11 ms
// Beats
// 94.86%

// Memory
// 10.8 MB
// Beats
// 49.38%