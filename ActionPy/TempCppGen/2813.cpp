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
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        sort(items.begin(), items.end(), [&](auto& a, auto&b)
        {
            return a[0] > b[0];
        });
        long long tmp = 0;
        long long ans = 0;
        unordered_set<int> st;
        stack<int> stk;
        for (int i = 0; i < k; ++i)
        {
            int p = items[i][0], c = items[i][1];
            tmp += p;
            if (!st.insert(c).second)
            {
                stk.push(p);
            }
        }
        ans = tmp + (long long )st.size() * (long long )st.size();
        for (int i = k; i < n; ++i)
        {
            int p = items[i][0], c = items[i][1];
            if (!stk.empty() && st.insert(c).second)
            {
                tmp += p - stk.top();
                stk.pop();
            }
            ans = max(ans , tmp + (long long )st.size() * (long long)st.size());
        }
        return ans;
    }
};
int main()
{
   return 0;
}