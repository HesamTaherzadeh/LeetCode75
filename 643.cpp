#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
class Solution
{
   public:
    double findMaxAverage(std::vector<int>& nums, int k)
    {
        size_t nums_size{nums.size()};
        double maxsum = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
        double sum    = maxsum;
        for (int i{k}; i < nums_size; ++i)
        {
            sum += nums[i] - nums[i - k];
            if (maxsum < sum)
            {
                maxsum = sum;
            }
        }
        return maxsum / k;
    }
};

int main()
{
    std::vector<int> vec{1, 12, -5, -6, 50, 3};
    Solution sol;
    std::cout << sol.findMaxAverage(vec, 4);
}