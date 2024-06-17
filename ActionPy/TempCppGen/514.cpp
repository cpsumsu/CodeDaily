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
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        // 從 m - 1開始，因為要從 dp[i][j + 1] 得出答案
        for (int j = m - 1; j >= 0; --j)
        {
            for (int i = n - 1; i >= 0; --i)
            {
                auto ch = key[j];
                int idx = 0;
                // 枚舉一下轉動n次直到到達目標字母
                for (int idx = 0; idx < n; ++idx)
                {
                    int pos = (i + idx) % n;
                    // 轉到了目標字母，可以加入答案
                    if (ring[pos] == ch)
                    {
                        // 這裡表示從左和從右選一個近的去
                        int mn = min(idx, n - idx);
                        if (j != m - 1)
                            // dp[pos][j+1] 表示從轉移到j+1的字母時，去到pos的位置消耗的步數
                            mn += dp[pos][j + 1];
                        dp[i][j] = min(dp[i][j], mn + 1);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
int main()
{
   return 0;
}