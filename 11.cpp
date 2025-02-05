#include <iostream>
#include <vector>

class Solution
{
   public:
    int maxArea(std::vector<int>& height)
    {
        size_t c_a{0}, c_b{height.size() - 1};
        int max{static_cast<int>((c_b - c_a)) * std::min(height.at(c_a), height.at(c_b))};
        int area = max;
        while (c_a != c_b)
        {
            int h_a = height.at(c_a);
            int h_b = height.at(c_b);
            if (h_a > h_b)
            {
                c_b--;
            } else
            {
                c_a++;
            }
            area = (c_b - c_a) * std::min(height.at(c_a), height.at(c_b));
            if (area > max) max = area;
        }

        return max;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{2, 1};
    std::cout << sol.maxArea(vec);
}
