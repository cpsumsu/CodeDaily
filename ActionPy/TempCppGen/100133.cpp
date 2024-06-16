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
    
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(1145, vector<int>(2, 0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = dp[i][1] = INT_MAX;
        dp[1][1] = prices[0];
        // dp[i][0]: 買前i個水果，不買第i個水果
        // dp[i][0]: 買前i個水果，買第i個水果
        for (int i = 1; i < n; ++i)
        {
            dp[i + 1][1] = min(dp[i][0], dp[i][1]) + prices[i];
            for (int j = i; j * 2 >= i + 1; j--)
                dp[i+1][0] = min(dp[i+1][0], dp[j][1]);
        }
        return min(dp[n][0], dp[n][1]);
    }
};
int main()
{
   return 0;
}