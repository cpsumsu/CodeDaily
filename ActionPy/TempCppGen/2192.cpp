#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    vector<vector<int>> mp;
    void dfs(vector<int>& vis, int x)
    {
        vis[x] = true;
        for (auto& y : mp[x])
        {
            if (!vis[y])
                dfs(vis, y);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        mp.resize(n);
        for (auto& e : edges) 
            mp[e[1]].push_back(e[0]);
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i)
        {
            vector<int> vis(n, false);
            dfs(vis, i);
            for (int v = 0; v < n; ++v)
            {
                if (vis[v] && v != i)
                    ans[i].push_back(v);
            }
        }
        return ans;

    }
};
int main()
{
   return 0;
}