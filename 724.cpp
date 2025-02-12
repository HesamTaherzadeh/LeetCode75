#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution
{
   public:
    int pivotIndex(std::vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int accum{0};
        for (int i{0}; i < nums.size(); ++i)
        {
            int cand{nums[i]};
            int temp = sum - accum;
            accum += cand;
            if (accum == temp) return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{1, 7, 3, 6, 5, 6};
    std::cout << sol.pivotIndex(vec) << std::endl;
}