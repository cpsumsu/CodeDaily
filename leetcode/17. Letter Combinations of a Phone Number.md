---
Difficulty: "Medium"
tags: ["Constructive algorithm"]
---


> Problem: [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

# 思路
- constructive algorithm
- details written in code

# 复杂度
- 时间复杂度:
> $O(N * M * N ^ 2) => O(N ^ 3)$
where N be the number of digits, M be the maximum number of string in pad (which is 4)

- 空间复杂度:
> $O(N)$

# Code
```c++
class Solution {
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
```