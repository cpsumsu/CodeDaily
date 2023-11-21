---
Difficulty: "Medium"
tags: ["Backtracking", "DFS"]
---

> Problem: [39. Combination Sum](https://leetcode.com/problems/combination-sum/description/)

# 思路
- fundamental dfs template
- notice `cur_ind`, since each time the candidates[i] may not start from i = 0
- friendly remainder: ignore the recursive lambda expression with `make_y_combinator` in formal interview

# 解题方法
> 

# 复杂度
- 时间复杂度:
> $O(n!)$ (not quite sure)

- 空间复杂度:
> $O(n^2)$ where n be the number of element candidates
  
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ret;
        vector<int> store;

        // this is a recursive lambda expression used in c++17, it can be written in several times. Or simply write recusion function outside the combinationSum function
        auto dfs = make_y_combinator([&](auto &dfs, int remain, int cur_ind) -> void {
            if (remain < 0) return ;

            if (remain == 0) {
                ret.push_back(store);
                return ;
            }

            for (int i = cur_ind; i < candidates.size(); i++) {
                int cur_val = candidates[i];

                store.push_back(cur_val);
                dfs(remain - cur_val, i);
                store.pop_back();
            }
        });

        dfs(target, 0);
        return ret;
    }
};
```