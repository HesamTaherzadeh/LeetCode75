#include <iostream>
#include <stack>
#include <string>

class Solution
{
   public:
    std::string decodeString(std::string s)
    {
        std::stack<int> opens;
        std::string out;
        size_t ss = s.size();

        for (size_t i = 0; i < ss; ++i)
        {
            char c = s[i];
            if (c == '[')
            {
                opens.push(i);
            } else if (c == ']')
            {
                int start = opens.top();
                opens.pop();

                int count    = 0;
                int numIndex = start - 1;
                while (numIndex >= 0 && isdigit(s[numIndex]))
                {
                    count++;
                    numIndex--;
                }
                count = std::stoi(s.substr(numIndex + 1, count))

                    std::string substring = s.substr(start + 1, i - start - 1);

                std::string repeated;
                for (int j = 0; j < count; ++j)
                {
                    repeated += substring;
                }

                s.replace(numIndex + 1, i - numIndex, repeated);

                i  = numIndex + repeated.size();
                ss = s.size();
            }
        }

        return s;
    }
};

int main()
{
    std::string s{"100[a]"};
    Solution sol;
    std::cout << sol.decodeString(s) << std::endl;  // Output: "accaccaccaaaa"
}