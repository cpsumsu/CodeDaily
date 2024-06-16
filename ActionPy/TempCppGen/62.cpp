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
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[j][i] = dp[j-1][i]+dp[j][i-1];
        }
    }
    return dp[m-1][n-1];
    }
};

class Solution_b {
public:
    int uniquePaths(int m, int n) {
    vector<int>dp(n,1);
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
    }
};
int main()
{
   return 0;
}