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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i = 0;i < n;++i) dp[i][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) 
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
int main()
{
   return 0;
}