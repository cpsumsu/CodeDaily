#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
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