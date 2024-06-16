#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int dfs(vector<vector<pair<int,int>>>& g, int signalSpeed, int x, int fa, int s)
    {
        int res = s % signalSpeed == 0;
        for (auto& [y,z] : g[x])
        {
            if (y != fa)
            {
                res += dfs(g,signalSpeed,y , x, s + z);
            }
        }
        return res;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> g(n);
        for (auto& e : edges)
        {
            int x = e[0], y = e[1], z = e[2];
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            if (g[i].size() == 1) 
                continue;
            int sum = 0;
            for (auto& [y, z] : g[i])
            {
                int r = dfs(g,signalSpeed,y,i,z);
                ans[i] += r * sum;
                sum += r;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}