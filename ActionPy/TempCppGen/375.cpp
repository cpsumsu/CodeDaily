#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= n; ++i) dp[i][i] = 0;
        for (int j = 2; j <= n; ++j)
            for (int i = j - 1; i >= 1; --i)
            {
                for (int k = i + 1; k <= j - 1; k++)
                    dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
                dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
                dp[i][j] = min(dp[i][j], j + dp[i][j - 1]);
            }
        return dp[1][n];
    }
};
int main()
{
   return 0;
}