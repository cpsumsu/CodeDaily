#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int minCut(string s) {
        // 第一次dp，算出s[i...j]是否是回文串
        vector<vector<bool>> isPalindromic(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || isPalindromic[i + 1][j - 1])) {
                    isPalindromic[i][j] = true;
                }
            }
        }
        int n = s.size();
        // 第二次dp，
        // dp[0] ~ dp[n + 1] 如果全不一樣，則dp[n + 1] = n
        // 如果 s[0...i] 是回文串，dp[i] = 0
        // 如果 s[j + 1...i] 是回文串，則分割1次，就變成找 dp[0...j] + 1 的情況
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) dp[i] = i;
        for (int i = 1; i < n; ++i) 
        {
            if (isPalindromic[0][i])
            {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j)
            {
                if (isPalindromic[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }
};
// aab
// aa b
// ab
int main()
{
   return 0;
}