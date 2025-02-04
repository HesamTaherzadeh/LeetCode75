#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int num : nums) {
            if (num <= first) {
                first = num; 
            } else if (num <= second) {
                second = num; 
            } else {
                return true;
            }
        }
        return false;
    }
};


int main(){
    Solution sol;
    std::vector<int> vec{20,100,10,12,5,13};
    std::cout << sol.increasingTriplet(vec);
}