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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i)
        {
            int x = maxHeights[i], y = x;
            long long s = x;
            for (int j = i - 1; j >= 0; --j)
            {
                x = min(x, maxHeights[j]);
                s += x;
            }
            for (int j = i + 1; j < n; ++j)
            {
                y = min(y, maxHeights[j]);
                s += y;
            }
            ans = max(ans, s);
        }
        return ans;
    }
};
int main()
{
   return 0;
}