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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        // dfs to DP
        // int m = grid.size(), n = grid[0].size();
        // function<int(int,int)> dfs = [&](int i, int j)->int{
        //     if (i == m - 1) return grid[i][j];
        //     int res = INT_MAX;
        //     for (int k = 0; k < n; ++k)
        //         res = min(res, dfs(i + 1, k) + moveCost[grid[i][j]][k]);
        //     return res + grid[i][j];
        // };
        // int ans = INT_MAX;
        // for (int i = 0; i < n; ++i)
        //     ans = min(ans, dfs(0, i));
        // return ans;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        f[m - 1] = grid[m - 1];
        for (int i = m - 2; i >= 0; i--)
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0;k < n; ++k)
                    f[i][j] = min(f[i][j], f[i+1][k] + moveCost[grid[i][j]][k]);
                f[i][j] += grid[i][j];
            }
        int mn = INT_MAX;
        for (auto a : f[0]) mn =min(mn, a);
        return mn;
    }
};
int main()
{
   return 0;
}