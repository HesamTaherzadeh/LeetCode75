#include <iostream>
#include <string>

 
class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        std::cout << "STR 1 " << str1 << " STR 2 " << str2 << std::endl;
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        if (str1 == str2) {
            return str1;
        }

        if (str1.size() > str2.size()) {
            return gcdOfStrings(str1.substr(str2.size()), str2);
        } else {
            return gcdOfStrings(str1, str2.substr(str1.size()));
        }
    }
};

int main() {
    Solution sol;
    std::string str1 = "ABABABAB";
    std::string str2 = "AB";
    std::cout << sol.gcdOfStrings(str1, str2); // Output: "ABAB"
    return 0;
}
