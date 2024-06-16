#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        int cnt[n]; memset(cnt, 0, sizeof(cnt));
        for (auto& t : trips)
        {
            int end = t[1];
            function<bool(int,int)> dfs = [&](int x, int fa) -> bool{
                if (x == end)
                {
                    ++cnt[x];
                    return true;
                }
                for (int y : g[x])
                {
                    if (y != fa && dfs(y, x))
                    {
                        ++cnt[x];
                        return true;
                    }
                }
                return false;
            };
            dfs(t[0], -1);
        }

        function<pair<int,int>(int,int)> dfs = [&](int x, int fa) -> pair<int, int> {
            int not_halve =  * cnt[x];
            int halve = not_halve / 2;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    auto [nh, h] = dfs(y, x);
                    not_halve += min(nh, h);
                    halve += nh;
                }
            }
            return {not_halve, halve};
        };
        auto [nh, h] = dfs(0, -1);
        return min(nh, h);
    }
};