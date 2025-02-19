#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution
{
   public:
    std::string removeStars(std::string s)
    {
        std::stack<char> stack_;
        size_t ss{s.size()};
        for (size_t i{ss}; i > 0; --i)
        {
            stack_.emplace(s[i - 1]);
        }
        std::string out;
        while (stack_.size())
        {
            char c{stack_.top()};
            if (c == '*')
            {
                out.pop_back();
            } else
            {
                out.push_back(c);
            }
            stack_.pop();
        }

        return out;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.removeStars("leet**cod*e");
}