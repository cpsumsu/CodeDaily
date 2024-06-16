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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
int main()
{
   return 0;
}