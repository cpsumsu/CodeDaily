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
    int minPathSum(vector<vector<int>>& grid) {
        // int m = sizeof(grid) / sizeof(grid[0]);
        // int n = sizeof(grid[0])/ sizeof(int);
        // the above methods are for 2D array, for vector(but ofcuz you can change to parameter input back to 2D array), we use the following:
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));    
        dp[0][0]= grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for(int j=1;j<m;j++){
            dp[j][0] = dp[j-1][0]+grid[j][0];
        }
        for(int i=1; i<m ; i++){    
            for(int j=1; j<n;j++){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        // same wth the last question, we can move FROM top or left
        return dp[m-1][n-1];
    }
};

class Solution_b {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m ; i++){
            for( int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                else if(i==0){
                    grid[i][j] += grid[i][j-1];
                }else if(j==0){
                    grid[i][j] += grid[i-1][j];
                }else{
                    grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
                }
            }}
            return grid[m-1][n-1];
        }
};
int main()
{
   return 0;
}