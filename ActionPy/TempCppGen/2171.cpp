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
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i-1] + beans[i-1];
        long long ans = prefix[n];
        for (int i = 0; i < n; ++i)
        {
            long long asum = prefix[n] - prefix[i];
            long long bsum = (long long)beans[i]*(n - i);
            ans = min(ans, prefix[i] + asum - bsum);
        }
        return ans;
    }
};
int main()
{
   return 0;
}