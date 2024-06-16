#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), ans = 0;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) 
            g[parent[i]].push_back(i);
        function<int(int)> dfs = [&](int x)
        {
            int xlen = 0;
            for (auto y : g[x])
            {
                int ylen = dfs(y) + 1;
                if (s[x] != s[y])
                {
                    ans = max(ans, xlen + ylen);
                    xlen = max(xlen, ylen);
                }
            }
            return xlen;
        };
        dfs(0);
        return ans + 1;
    }
};
int main()
{
   return 0;
}