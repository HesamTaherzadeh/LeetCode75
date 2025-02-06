#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

#include <unordered_map>
#include <vector>

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
    public:
        int maxOperations(std::vector<int>& nums, int k) {
            std::unordered_map<int, int> freq;
            int count = 0;
            
            for (int num : nums) {
                int complement = k - num;
                
                if (freq[complement] > 0) {
                    count++;
                    freq[complement]--;
                } else {
                    freq[num]++;
                }
            }
            
            return count;
    }

    int maxOperations_two_pointers(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());  
        size_t c1 = 0, c2 = nums.size() - 1;
        int count = 0;

        while (c1 < c2) {  
            int sum = nums[c1] + nums[c2];
            
            if (sum == k) {
                count++;   
                c1++;
                c2--;
            } else if (sum < k) {
                c1++;
            } else {
                c2--; 
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{3,1,3,4,3};
    std::cout << sol.maxOperations_two_pointers(vec, 6) << std::endl;
}
