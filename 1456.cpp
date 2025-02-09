#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
   public:
    std::vector<char> vowels{'a', 'e', 'o', 'u', 'i'};
    int maxVowels(std::string s, int k)
    {
        auto is_vowel = [this](char element) {
            return std::find(vowels.begin(), vowels.end(), element) != vowels.end();
        };
        size_t ss{s.size()};
        int max_count{0}, count{0};
        for (int i{0}; i < k; i++)
        {
            if (is_vowel(s[i])) max_count++;
        }
        count = max_count;

        for (int i{k}; i < ss; i++)
        {
            if (is_vowel(s[i - k]))
            {
                count--;
            }
            if (is_vowel(s[i]))
            {
                count++;
            }
            max_count = std::max(count, max_count);
        }

        return max_count;
    }
};

int main()
{
    std::string s{"abciiidef"};
    Solution sol;
    std::cout << sol.maxVowels(s, 3);
}