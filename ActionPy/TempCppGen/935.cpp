#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> path = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
    int knightDialer(int n) {
        vector<vector<int>> dp(n, vector<int>(10, 0));
        for (int i = 0; i < 10; ++i)
            dp[0][i] = 1;
        for (int k = 1; k < n; ++k)
            for (int i = 0; i < 10; ++i)
                for (auto a : path[i])
                    dp[k][i] = (dp[k][i] + dp[k - 1][a]) % MOD;
        int ans = 0;
        for (int i = 0; i < 10; ++i)
            ans = (ans + dp[n-1][i]) % MOD;
        return ans;
    }
};
int main()
{
   return 0;
}