#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        int dp[m][n];
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j<n ; j++){
               dp[i][j] = int(matrix[i][j]-'0');
               ans = max(ans, dp[i][j]);
            }
        }
        for(int i = 1; i < m ; i++){
            for(int j = 1 ; j<n ; j++){
                if(dp[i][j]==1) {
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1; 
                    ans = max(ans, dp[i][j]);
                }   
            }
        }
        return ans*ans;
    }
};
int main()
{
   return 0;
}