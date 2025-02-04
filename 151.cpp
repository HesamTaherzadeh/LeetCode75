#include <iostream>
#include <stack>
#include <sstream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stack<std::string> words;
        std::string word;
        
        for (char c : s) {
            if (c != ' ') {
                word.push_back(c);
            } else if (!word.empty()) {
                words.push(word);
                word.clear();
            }
        }
        if (!word.empty()) words.push(word); // Push last word if any

        std::ostringstream out;
        while (!words.empty()) {
            out << words.top();
            words.pop();
            if (!words.empty()) out << " ";
        }
        
        return out.str();
    }
};


int main() {
    Solution sol;
    std::cout << sol.reverseWords(" the sky is blue  "); 
    return 0;
}
