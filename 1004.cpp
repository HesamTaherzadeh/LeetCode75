#include <algorithm>
#include <iostream>
#include <vector>

const auto _ = std::cin.tie(nullptr) -> sync_with_stdio(false);

class Solution
{
   public:
    int longestOnes(std::vector<int>& nums, int k)
    {
        int max_ones{0};
        int potential{k};
        int all_time_max{0};
        int first_zero{-1};
        size_t nums_s{nums.size()};
        for (int i{0}; i < nums_s; i++)
        {
            if (nums[i])
            {
                max_ones++;
            } else
            {
                if (first_zero == -1)
                {
                    first_zero = i;
                }
                if (potential)
                {
                    potential--;
                    max_ones++;
                } else
                {
                    all_time_max = std::max(max_ones, all_time_max);
                    max_ones     = 0;
                    potential    = k;
                    i            = first_zero;
                    first_zero   = -1;
                }
            }
        }

        return std::max(all_time_max, max_ones);
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{0, 0, 0, 1};
    std::cout << sol.longestOnes(vec, 4) << std::endl;
}
