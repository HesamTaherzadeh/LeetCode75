#include <iostream>
#include <vector>

class Solution
{
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        std::vector<int> out;
        std::vector<int> suffix(nums.size(), 1.0), prefix(nums.size(), 1.0);
        int vector_size = nums.size();
        for (int i{1}; i < vector_size + 1; i++)
        {
            suffix[i] = suffix[i - 1] * nums[i - 1];
        }
        for (int num : suffix)
        {
            std::cout << num << " ";
        }
        return out;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{1, 2, 3, 4};
    auto vec_out = sol.productExceptSelf(vec);

    std::cout << "\n";
    return 0;
}
