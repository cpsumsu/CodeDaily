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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp (n,0);
        for(int i = 0; i<n;i++) dp[i] = triangle[n-1][i];
        for(int i = n-1; i>0; i--){
            for(int j=0 ; j<i; j++){
                dp[j] = min(dp[j],dp[j+1])+ triangle[i-1][j];
            }
        }
        return dp[0];
    }
};
int main()
{
   return 0;
}