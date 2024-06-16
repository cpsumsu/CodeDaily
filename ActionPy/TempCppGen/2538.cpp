#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        long ans = 0;
        function<pair<long, long>(int, int)> dfs = [&](int x, int fa) -> pair<long,long> {
            long p = price[x], max_s1 = p, max_s2 = 0;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    auto [s1, s2] = dfs(y, x);
                    ans = max({ans, max_s1 + s2, max_s2 + s1});
                    max_s1 = max(max_s1, s1 + p);
                    max_s2 = max(max_s2, s2 + p);
                }
            }
            return {max_s1, max_s2};
        };
        dfs(0, -1);
        return ans;
    }
};