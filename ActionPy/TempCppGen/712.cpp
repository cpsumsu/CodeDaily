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
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp (n+1, vector<int>(m+1,0));
        // my little draft: 
        //     ''   s   e   a
        // ''  0    s   se  sea  
        // e   e    es  --   
        // a   ea   eas     --
        // t   eat
        for(int i = 1; i<=n; i++){
            dp[i][0] = dp[i-1][0] + (int) s1[i-1];
        }
        for(int j = 1;j<=m;j++){
            dp[0][j] = dp[0][j-1] + (int) s2[j-1];
        }
        for( int i=1; i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i][j-1]+(int)s2[j-1],dp[i-1][j]+(int)s1[i-1]) ;
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{
   return 0;
}