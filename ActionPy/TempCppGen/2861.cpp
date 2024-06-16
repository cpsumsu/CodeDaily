#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        // 枚舉機械
        for (int i = 0; i < k; ++i) 
        {
            int l = 0, r = 2 * 1e8;
            while(l <= r)
            {
                // 做 mid 份合金
                int mid = (l + r) >> 1;
                long long val = 0;
                // 枚舉合金消耗量
                for (int j = 0; j < n; ++j)
                {
                    // 如果第j份不夠做mid份合金，就花錢
                    if (stock[j] < 1LL * mid * composition[i][j])
                    {
                        val += (1LL * mid * composition[i][j] - 1LL * stock[j]) * cost[j];
                    }
                    // 超出 budget 
                    if (val > 1LL * budget) break;
                }
                // 沒超支，下次就做多點合金
                if (val <= 1LL * budget)
                {
                    ans = fmax(ans, mid);
                    l = mid + 1;
                }
                // 超了，不做這麼多了
                else
                {
                    r = mid - 1;
                }
            }
        }

        return ans;
    }
};