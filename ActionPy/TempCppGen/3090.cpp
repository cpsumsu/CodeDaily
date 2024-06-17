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
    int maximumLengthSubstring(string s) {
        int start = 0, end = 0, n = s.size(), ans = 0;
        unordered_map<char, int> m;

        while (end < n) {
            m[s[end]]++;

            while (m[s[end]] > 2) {
                m[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};
int main()
{
   return 0;
}