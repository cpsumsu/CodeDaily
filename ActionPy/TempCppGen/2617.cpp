#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
#include <unordered_set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <cassert>
#include <cmath>
#include <cstdint>
using namespace std;


class Solution_a {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0 && i != m - 1 && j != n - 1) continue;
                if (dp[i][j] == INT_MAX) continue;
                for (int k = 1; k <= grid[i][j]; ++k)
                {
                    if (k + j < n)
                        dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
                    if (k + i < m)
                        dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m - 1][n - 1] == INT_MAX ? -1 : dp[m-1][n-1];
    }
};

class Solution_b {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), a = 0;
        vector<priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>>> heaps(n);
        for (int i = 0; i < m; ++i)
        {
            priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> row;
            for (int j = 0; j < n; ++j)
            {
                while(!row.empty() && row.top().second < j)
                    row.pop();
                auto& col = heaps[j];
                while(!col.empty() && col.top().second < i)
                    col.pop();
                a = i || j ? INT_MAX : 1; 
                
                if (!row.empty()) a = row.top().first + 1;
                if (!col.empty()) a = min(a, col.top().first + 1);

                int k = grid[i][j];
                if (k && a != INT_MAX)
                {
                    row.emplace(a, k + j);
                    col.emplace(a, k + i);
                }
            }
            // cout << endl;
        }
        return a == INT_MAX ? -1 : a;
    }
};
int main()
{
   return 0;
}