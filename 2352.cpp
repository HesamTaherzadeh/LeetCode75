#include <iostream>
#include <map>
#include <vector>

// struct VectorHash {
//     std::size_t operator()(const std::vector<int>& v) const {
//         std::size_t hash = 0;
//         for (int num : v) {
//             hash ^= std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
//         }
//         return hash;
//     }
// };

class Solution
{
   public:
    int equalPairs(std::vector<std::vector<int>>& grid)
    {
        size_t n{grid.size()};
        std::map<std::vector<int>, int> col, row;
        int count{0};
        for (int i{0}; i < n; ++i)
        {
            row[grid[i]]++;
            std::vector<int> temp;
            for (int j{0}; j < n; ++j)
            {
                temp.push_back(grid[j][i]);
            }
            col[temp]++;
        }

        for (const auto& r : row)
        {
            count += r.second * col[r.first];
        }
        return count;
    }
};

int main()
{
    // std::vector<std::vector<int>> grid = {
    // {3, 1, 2, 2},
    // {1, 4, 4, 5},
    // {2, 4, 2, 2},
    // {2, 4, 2, 2}
    // };
    std::vector<std::vector<int>> grid = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7},
    };
    Solution sol;
    std::cout << " " << sol.equalPairs(grid);
}