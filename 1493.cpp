#include <algorithm>
#include <iostream>
#include <vector>

const auto _ = std::cin.tie(nullptr) -> sync_with_stdio(false);

class Solution
{
   public:
    int longestSubarray(std::vector<int>& nums)
    {
        int left       = 0;
        int right      = 0;
        int max_length = 0;
        int zero_count = 0;

        while (right < nums.size())
        {
            if (!nums[right])
            {
                zero_count++;
            }

            while (zero_count > 1)
            {
                if (nums[left] == 0)
                {
                    zero_count--;
                }
                left++;
            }

            max_length = std::max(max_length, right - left);
            right++;
        }

        return max_length;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{1, 1, 1};
    std::cout << sol.longestSubarray(vec) << std::endl;
}
