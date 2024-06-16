#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;


class Solution_a {
public:
    const int MOD = 1e9 + 7;
    long long pow(long long x, long long a)
    {
        long long p = x;
        while(a--)
        {
            p = (p * x + MOD) % MOD;
        }
        return p % MOD;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [&](auto& a, auto& b)
        {
            return a[0] < b[0];
        });
        int cnt = 1, ed = ranges[0][1];
        for (int i = 1; i < ranges.size(); ++i)
        {
            if (ranges[i][0] > ed)
            {
                // cout << ed << " " << ranges[i][0] << endl;
                cnt++;
            }
            ed = max(ranges[i][1], ed);
        }
        return (int)pow(2,cnt - 1);
    }
};
int main()
{
   return 0;
}