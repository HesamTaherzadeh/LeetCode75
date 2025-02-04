#include <string>
#include <iostream>


class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        size_t ss {s.size()};
        int counter {0};
        for(char c : t){
            if (c == s[counter]){
                counter++;
            }
        }
        return counter == ss ? true : false;
    }
};



int main(){
    Solution sol;
    std::string s1{"abc"};
    std::string s2{"ahbgdc"};

    std::cout << sol.isSubsequence(s1, s2);
}