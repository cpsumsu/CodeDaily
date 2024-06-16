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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 114));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= amount; ++j)
            {
                if (j < coins[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = dp[i][j] + dp[i + 1][j - coins[i]]; 
            }
        }
        return dp[n][amount];
    }
};
int main()
{
   return 0;
}