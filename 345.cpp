#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    const std::vector<char> vowels{'a', 'e', 'o', 'u', 'A', 'E', 'O', 'U', 'i', 'I'};
    std::string reverseVowels(std::string s) {
        int ss = s.size();
        std::stack<char> vowels_found;
        for(int i{0}; i < ss; i++){
            if(std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end()){  
                vowels_found.emplace(s[i]);
                s[i] = '%';
            }
        }
        for(int j{0}; j < ss; j++){
            if(s[j] == '%'){  
                s[j] = vowels_found.top();
                vowels_found.pop();
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    std::cout << sol.reverseVowels("IceCreAm"); 
    return 0;
}



