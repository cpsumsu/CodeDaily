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
    int distance(char a, char b)
    {
        return min((a - b + 26) % 26, (b - a + 26) % 26);
    }
    string getSmallestString(string s, int k) {
        if (k == 0) return s;
        int n = s.size();
        vector<char> pre(n, 'a');
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'a') continue;
            for (int j = 0; j < 26; ++j)
            {
                if (distance(s[i], 'a' + j) <= k)
                {
                    // cout << (char)('a' + j) << endl;
                    pre[i] = 'a' + j;
                    k -= distance(s[i], 'a' + j);
                    break;
                }
            }
        }
        string ans = "";
        for (auto a : pre) ans += a;
        return ans;
    }
};
int main()
{
   return 0;
}