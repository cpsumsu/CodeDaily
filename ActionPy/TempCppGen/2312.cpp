#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (auto& p : prices)
        {
            int x = p[0], y = p[1], z = p[2];
            dp[x][y] = z;
        }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k < j; ++k) dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                for (int k = 1; k < i; ++k) dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
        return dp[m][n];
    }
};

class Solution_b {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (auto& p : prices)
        {
            int x = p[0], y = p[1], z = p[2];
            dp[x][y] = z;
        }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= j / 2; ++k) dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                for (int k = 1; k <= i / 2; ++k) dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
        return dp[m][n];
    }
};
int main()
{
   return 0;
}