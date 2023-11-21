---
Difficulty: "Medium"
tags: ["Backtracking", "DFS"]
---

> Problem: [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/)

# Reasoning 
- the idea is to enumerate all the possible way of combination of '(' and ')'
- use dfs traverse (say, tree, imagine it is an pre-order traversal) 
- but we have to make sure '(' must have greater number than that of ')' prior to the ')'
- so `if (left > 0) dfs()` comes first and `if (right > left)` makes sure that wouldn't have more ')' prior to '('


# Code
```c++
class Solution {
private:
    template <class F>
    struct y_combinator {
        F f; 

        template <class... Args>
        decltype(auto) operator()(Args&&... args) const {
            return f(*this, std::forward<Args>(args)...);
        }
    };

    template <class F> y_combinator<std::decay_t<F>> make_y_combinator(F&& f) { return {std::forward<F>(f)}; }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ret;

        auto dfs = make_y_combinator([&](auto &dfs, string str, int left, int right) {
            if (left == 0 && right == 0) {
                ret.push_back(str);
                return ;
            }

            if (left > 0)
                dfs(str + '(', left - 1, right);
            if (right > left)
                dfs(str + ')', left, right - 1);
        });

        dfs("", n, n);
        return ret;
    }
};
```	