#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int n;
    void ok(long long *f, vector<int>& maxHeights)
    {
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while(!stk.empty() && maxHeights[stk.top()] >= maxHeights[i]) 
                stk.pop();  
            
            if (stk.empty()) 
                f[i] = 1LL * maxHeights[i] * (i + 1);
            else 
                f[i] = f[stk.top()] + 1LL * maxHeights[i] * (i - stk.top());
            stk.push(i);
        }
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        n = maxHeights.size();
        long long f[n];
        ok(f, maxHeights);
        long long g[n];
        reverse(maxHeights.begin(), maxHeights.end());
        ok(g, maxHeights);
        reverse(maxHeights.begin(), maxHeights.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[i] + g[n - 1 - i] - maxHeights[i]);
        return ans;
    }
};