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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int>dp(n,1);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1) dp[j] = 0;
                else if(i==0 && j==0) continue;
                else if(i==0) dp[j] = dp[j-1];
                else if(j==0) continue;
                else dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    } 
};
int main()
{
   return 0;
}