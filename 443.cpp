#include <vector>
#include <iostream>
#include <map>
#include <cstring>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int i{0}, count{0};
        char previous_char{chars[0]};
        chars.push_back('-');
        for(char character: chars){
            if (previous_char != character){
                chars[i++] = previous_char;
                if (count != 1){
                    std::string countStr = std::to_string(count);
                    const char* charcount = countStr.c_str();
                    for(int j{0}; j < strlen(charcount); j++){
                        chars[i++] = charcount[j];
                    }
                }
                
                previous_char = character;
                count = 1;
            }else{
                count += 1;
            }

        }
        chars.erase(chars.begin() + i, chars.end());

        return i;
    }
};


int main() {
    std::vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'a'};
    Solution sol;
    sol.compress(chars);
    for(char char_: chars){
        std::cout << char_;
    }
    return 0;
}