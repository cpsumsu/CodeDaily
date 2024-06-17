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
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, ans = 0;
        vector<int> lm(n, height[0]), rm(n, height[n - 1]);
        for (int i = 1; i < n; ++i) lm[i] = max(lm[i - 1], height[i]);
        for (int i = n - 2; i >= 0; --i) rm[i] = max(rm[i + 1], height[i]);
        for (int i = 0; i < n; ++i)
        {
            ans += max(min(lm[i], rm[i]) - height[i], 0);
        }
        return ans;
    }
};

class Solution_b {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, ans = 0;
        int lm = 0, rm = 0;
        while(l <= r)
        {
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);
            if (lm < rm)
                ans += lm - height[l], l++;
            else
                ans += rm - height[r], r--;
        }
        return ans;
    }
};
int main()
{
   return 0;
}