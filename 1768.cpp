#include <iostream>
#include <string>

class Solution
{
   public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        std::string combined;
        int s2           = word2.size();
        int s1           = word1.size();
        int smaller_size = std::min(s2, s1);
        int idx{0};
        while (idx < smaller_size)
        {
            combined += word1[idx];  // Append character from word1
            combined += word2[idx];  // Append character from word2
            idx++;
        }

        if (smaller_size == s2)
        {
            combined.append(word1, idx, s1);
        } else
        {
            combined.append(word2, idx, s2);
        }
        return combined;
    }
};

int main()
{
    Solution sol;
    std::string str1{"abc"};
    std::string str2{"pqr"};
    std::cout << sol.mergeAlternately(str1, str2);
}