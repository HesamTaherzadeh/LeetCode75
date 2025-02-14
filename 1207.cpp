#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
   public:
    bool uniqueOccurrences(std::vector<int>& arr)
    {
        std::unordered_map<int, int> umap;

        for (int num : arr)
        {
            umap[num]++;
        }

        std::unordered_set<int> occurrences;

        for (const auto& pair : umap)
        {
            int count = pair.second;
            if (occurrences.count(count) > 0)
            {
                return false;
            }
            occurrences.insert(count);
        }

        return true;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec1{1, 2, 2, 1, 1, 3};
    std::cout << " " << sol.uniqueOccurrences(vec1);
}