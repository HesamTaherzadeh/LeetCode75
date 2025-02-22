#include <iostream>
#include <queue>

class RecentCounter
{
   public:
    int count_;
    std::queue<int> q_;

    RecentCounter() : count_(0) {}

    int ping(int t)
    {
        q_.emplace(t);

        while (!q_.empty() && q_.front() < t - 3000)
        {
            q_.pop();
        }

        count_ = q_.size();

        return count_;
    }
};

int main()
{
    RecentCounter recentCounter = RecentCounter();
    std::cout << recentCounter.ping(1) << "\n";  // requests = [1], range is [-2999,1], return 1
    std::cout << recentCounter.ping(100)
              << "\n";  // requests = [1, 100], range is [-2900,100], return 2
    std::cout << recentCounter.ping(3001)
              << "\n";  // requests = [1, 100, 3001], range is [1,3001], return 3
    std::cout << recentCounter.ping(3002)
              << "\n";  // requests = [1, 100, 3001, 3002], range is [2,3002],
}