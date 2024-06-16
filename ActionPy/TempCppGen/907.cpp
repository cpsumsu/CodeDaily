#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n , -1);
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        vector<int> right(n , n);
        while(!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }
        long ans = 0L;
        for (int i = 0; i < n; ++i)
            ans += (long) arr[i] * (i - left[i]) * (right[i] - i);
        return ans % MOD;
    }
};

class Solution_b {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        long ans = 0L;
        arr.push_back(-1);
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        for (int r = 0; r < n; ++r)
        {
            while(st.size() > 1 && arr[st.top()] >= arr[r])
            {
                int cur = st.top();
                st.pop();
                ans += (long) arr[cur] * (cur - st.top()) * (r - cur);
            }
            st.push(r);
        }
        return ans % MOD;
    }
};