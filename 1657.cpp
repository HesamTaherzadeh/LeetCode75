#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
   public:
    bool closeStrings(std::string word1, std::string word2)
    {
        if (word1.length() != word2.length())
        {
            return false;
        }

        std::unordered_map<char, int> umap1, umap2;
        std::vector<int> frequency1, frequency2;
        std::vector<char> chars1, chars2;

        for (const char c : word1)
        {
            umap1[c]++;
        }
        for (const char c : word2)
        {
            umap2[c]++;
        }

        for (auto p : umap1)
        {
            frequency1.push_back(p.second);
            chars1.push_back(p.first);
        }
        for (auto p : umap2)
        {
            frequency2.push_back(p.second);
            chars2.push_back(p.first);
        }

        std::sort(frequency1.begin(), frequency1.end());
        std::sort(frequency2.begin(), frequency2.end());
        std::sort(chars1.begin(), chars1.end());
        std::sort(chars2.begin(), chars2.end());

        return frequency1 == frequency2 && chars1 == chars2;
    }
};

int main()
{
    Solution sol;
    std::string s1{"cabbba"};
    std::string s2{"abbccc"};
    std::cout << " " << sol.closeStrings(s1, s2);
}