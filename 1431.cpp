#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
   public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
    {
        std::vector<int> sortedCandies = candies;
        std::sort(sortedCandies.begin(), sortedCandies.end());
        std::vector<bool> willorwillnot;
        for (int i{0}; i < candies.size(); ++i)
        {
            auto idx = std::upper_bound(candies.begin(), candies.end(), candies[i] + extraCandies);
            idx == sortedCandies.end() ? willorwillnot.push_back(false)
                                       : willorwillnot.push_back(true);
        }
        return willorwillnot;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{2, 3, 5, 1, 3};
    auto worw = sol.kidsWithCandies(vec, 3);
    for (auto state : worw)
    {
        std::cout << state << " ";
    }
}
