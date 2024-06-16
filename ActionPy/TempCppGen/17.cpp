#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;


class Solution_a {
public:
    // use hash map store as well
    const vector<string> pad = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        // very important to append empty string, otherwise line 19 would not implement for empty vector
        result.push_back("");
        
        for (auto digit : digits) {
            vector<string> tmp;

            for (auto candidate : pad[digit - '2']) {
                // for each element in result, append the new character 
                for (auto s : result) {
                    // store them into tmp so that tmp currently becomes the answer
                    tmp.push_back(s + candidate);
                }
            }

            result.swap(tmp);
        }

        return result;
    }
};
int main()
{
   return 0;
}