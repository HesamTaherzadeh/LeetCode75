#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
   public:
    int largestAltitude(std::vector<int>& gain)
    {
        int max{0}, sum{0};

        for (int alt : gain)
        {
            sum += alt;
            max = std::max(max, sum);
        }
        return max;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{-4, -3, -2, -1, 4, 3, 2};
    std::cout << sol.largestAltitude(vec) << std::endl;
}