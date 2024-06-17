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
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> ans;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0) dp[i][j] = matrix[i][j];
                else if (i == 0) dp[i][j] = dp[i][j - 1] ^ matrix[i][j];
                else if (j == 0) dp[i][j] = dp[i - 1][j] ^ matrix[i][j];
                else dp[i][j] = dp[i - 1][j] ^ matrix[i][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1];
                ans.push_back(dp[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        // for (auto& a : ans) cout << a << endl;
        return ans[ans.size() - k];
    }
};
int main()
{
   return 0;
}