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
    const int MOD = 1e9 + 7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> dp(n);
        for (int i = 0; i < n - 1; ++i)
        {
            // 連獏帶猜 
            // * 2: 循環一次，就得再做一次
            // + 2: 因為只有i房間才能去 i + 1 房間
            // - dp[nextVisit[i]]: 我也不知道，感覺是因為循環的時候回去的房間也要時間，猜的
            dp[i + 1] = (dp[i] * 2 + 2 - dp[nextVisit[i]] + MOD) % MOD;
            // mod ) % mod:
            // 小心以下例子
            // [0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48]
        }
        return dp[n - 1];
    }
};
int main()
{
   return 0;
}