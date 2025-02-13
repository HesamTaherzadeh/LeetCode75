#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution
{
   public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<int, int> map_1, map_2;
        std::vector<int> vec1, vec2;
        size_t n_s1{nums1.size()}, n_s2{nums2.size()};

        for (int i{0}; i < n_s1; i++)
        {
            map_1[nums1[i]] += 1;
        }
        for (int i{0}; i < n_s2; i++)
        {
            map_2[nums2[i]] += 1;
        }

        for (int i{0}; i < n_s1; i++)
        {
            int num  = nums1[i];
            int cand = map_2[num];
            if (!cand && cand != -1)
            {
                vec1.push_back(num);
                map_2[num] = -1;
            }
        }

        for (int i{0}; i < n_s2; i++)
        {
            int num  = nums2[i];
            int cand = map_1[num];
            if (!cand && cand != -1)
            {
                vec2.push_back(num);
                map_1[num] = -1;
            }
        }

        return {vec1, vec2};
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec1{1, 2, 3};
    std::vector<int> vec2{2, 4, 6};
    auto out = sol.findDifference(vec1, vec2);

    for (auto num_vec : out)
    {
        for (auto num : num_vec)
        {
            std::cout << num << std::endl;
        };
    }
}