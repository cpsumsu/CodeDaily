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
    int cla(vector<int>& a)
    {
        int cnt = 1;
        int res = 1;
        for (int i = 1; i < a.size(); ++i)
        {
            if (a[i] == a[i - 1] + 1)
            {
                cnt++;
                res = max(res, cnt);
            }
            else
                cnt = 1;
        }
        return res;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int ans = min(cla(hBars), cla(vBars)) + 1;
        return ans * ans;
    }
};
int main()
{
   return 0;
}