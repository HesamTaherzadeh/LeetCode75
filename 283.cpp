#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
   public:
    void moveZeroes(std::vector<int>& nums)
    {
        int k1{0}, k2{0};
        size_t vsize{nums.size()};
        for (int i{0}; i < vsize; i++)
        {
            if (nums[i])
            {
                nums[k1++] = nums[i];
            } else
            {
                k2++;
            }
        }

        for (int i{0}; i < k2; i++)
        {
            nums[vsize - 1 - i] = 0;
        }
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{0, 1, 0, 3, 12};
    sol.moveZeroes(vec);
    for (int num : vec)
    {
        std::cout << num << std::endl;
    }
}