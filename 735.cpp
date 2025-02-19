#include <iostream>
#include <stack>
#include <vector>

class Solution
{
   public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids)
    {
        std::stack<int> stack;
        std::vector<int> out;

        for (int i = 0; i < asteroids.size(); ++i)
        {
            int current = asteroids[i];

            while (!stack.empty() && stack.top() > 0 && current < 0 && stack.top() < -current)
            {
                stack.pop();
            }

            if (stack.empty() || current > 0 || stack.top() < 0)
            {
                stack.push(current);
            } else if (current < 0 && stack.top() == -current)
            {
                stack.pop();
            }
        }

        while (!stack.empty())
        {
            out.insert(out.begin(), stack.top());
            stack.pop();
        }

        return out;
    }
};

int main()
{
    Solution sol;
    std::vector<int> input{5, 10, -5};
    std::vector<int> out = sol.asteroidCollision(input);

    for (int asteriod : out)
    {
        std::cout << asteriod << std::endl;
    }
}