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
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (st.size()) {
                    st.pop();

                    if (st.size())
                        ans = max(ans, i - st.top());
                    else 
                        st.push(i);
                }
            }
        }

        return ans;
    }
};

class Solution_b {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == ')')
            {
                auto pre = i - dp[i-1] - 1;
                if (pre >= 0 && s[pre] == '(')
                {
                    dp[i] = dp[i-1] + 2;
                    if (pre > 0)
                    {
                        dp[i] += dp[pre-1];
                    }
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}