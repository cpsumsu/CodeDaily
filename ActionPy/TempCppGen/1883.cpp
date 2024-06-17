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
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        if (accumulate(dist.begin(), dist.end(), 0) > (long long) speed * hoursBefore) 
        {
            return -1;
        }
        int n = dist.size();
        vector<vector<int>> f(n, vector<int>(n, - 1));
        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if (j < 0) 
                return 0;
            auto& t = f[i][j];
            if (t != -1) 
                return t;
            // 不跳過：先算出在最多跳過i 次的情況下，從 dist[0] 到 dist[j−1] 所需的最小時間
            t = (dfs(i, j - 1) + dist[j] + speed - 1) / speed * speed;
            // 跳过：先算出在最多跳过 i−1 次的情况下，从 dist[0] 到 dist[j−1] 需要的最小时间，即 dfs(i−1,j−1)，然后加上 dist[j] 需要的时间
            if (i)
                t = min(t, dfs(i - 1, j - 1) + dist[j]);
            return t;
        };
        int i;
        for (i = 0;i <= n; i++)
        {
            // dfs(i,n−2)。注意 dist[n−1] 无需跳过，单独计算
            if (dfs(i, n - 2) + dist[n - 1] <= (long long) speed * hoursBefore)
                break;
        }
        return i;
    }
};
int main()
{
   return 0;
}