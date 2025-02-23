#include <iostream>
#include <queue>
#include <string>

class Solution
{
   public:
    std::string predictPartyVictory(std::string senate)
    {
        std::queue<int> r, d;
        int n = senate.size();

        for (int i = 0; i < n; ++i)
        {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (!r.empty() && !d.empty())
        {
            int rIndex = r.front();
            int dIndex = d.front();
            r.pop();
            d.pop();

            if (rIndex < dIndex)
            {
                r.push(rIndex + n);
            } else
            {
                d.push(dIndex + n);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};

int main()
{
    Solution sol;
    std::cout << sol.predictPartyVictory("RDDDDRRR");
}