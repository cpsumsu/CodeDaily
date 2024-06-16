#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while(!st.empty() && st.top() < heights[i])
            {
                st.pop();
                ans[i]++;
            }
            if (!st.empty())
            {
                // ans[i] = st.size()
                ans[i]++;
            }
            st.push(heights[i]);
        }
        return ans;
    }
};

class Solution_b {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ret(n);

        for (int i = 0; i < n - 1; i++) {
            int cnt = 0, maxi = 0;

            for (int j = i; j < n; j++) {
                if (heights[i] > maxi && j + 1 < n) {
                    if (maxi < heights[j + 1]) {
                        maxi = heights[j + 1];
                        cnt++;
                    }
                } else {
                    break;
                }
            }

            ret[i] = cnt == 0 ? 1 : cnt;
        }

        ret.back() = 0;
        return ret;
    }
};
int main()
{
   return 0;
}