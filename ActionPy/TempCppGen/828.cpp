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
    int uniqueLetterString(string s) {
        vector<vector<int>> dp(26, {-1});
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i)
            dp[s[i] - 'A'].push_back(i); // 找每個字符在s中出現的位置
        for (auto& a : dp)
        {
            a.push_back(s.size());
            for (int j = 1; j < a.size() - 1; ++j)
            {
                // s[:i]的子串
                // 以 s[i-1] 結尾的子串加上 $s[i]$
                // $s[i]$ 自身
                // 找 s[j] 的左右兩邊乘積
                int res = (a[j] - a[j - 1]) * (a[j + 1] - a[j]);
                ans += res;
            }
        }
        return ans;
    }
};

class Solution_b {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> index(26, {-1, -1});
        int N = s.size(), res = 0;

        for (int i = 0; i < N; i++) {
            int c = s[i] - 'A';
            res += (i - index[c][1]) * (index[c][1] - index[c][0]);
            index[c][0] = index[c][1];
            index[c][1] = i;
        }

        for (int c = 0; c < 26; c++) 
            res += (N - index[c][1]) * (index[c][1] - index[c][0]);

        return res;
    }
};

class Solution_c {
public:
    unordered_map<string,int> ook;
    int ok(string sub)
    {
        int val[26] = {0};
        for (auto a : sub)
            val[a - 'A'] += 1;
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            if (val[i] == 1) ans += 1;
        ook[sub] = ans;
        return ans;
    }
    int uniqueLetterString(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> dp(n , vector<int>(n, 0));
        unordered_map<string,int> mp;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (i == 0)
                {
                    mp[to_string(s[i])] += 1;
                    continue;
                }
                string sub = s.substr(i - 1, j - i + 2);
                cout << sub << endl;
                if (ook[sub]) mp[sub] += ook[sub];
                else mp[sub] += ok(sub);
            }
        }
        for (auto [u,v] : mp)
        {
            ans += v;
        }
        return ans;
    }
};
int main()
{
   return 0;
}