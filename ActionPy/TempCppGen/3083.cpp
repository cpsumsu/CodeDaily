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
    bool isSubstringPresent(string s) {
        bool vis[26][26] = {0};
        for (int i = 1; i < s.length(); ++i)
        {
            int x = s[i - 1] - 'a', y = s[i] - 'a';
            vis[x][y] = true;
            if (vis[y][x]) return true;
        }
        return false;
    }
};
int main()
{
   return 0;
}