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
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> mp(dictionary.begin(), dictionary.end());
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; ++j)
            {
                if (mp.count(s.substr(j, i - j)))
                {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};
int main()
{
   return 0;
}