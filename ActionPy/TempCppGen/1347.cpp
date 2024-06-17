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
    int minSteps(string s, string t) {
        vector<int> brucket(26);

        for (auto &x : s)
            brucket[x-'a']++;

        for (auto &x : t)
            brucket[x-'a']--;

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += abs(brucket[i]);

        return cnt / 2;
    }
};
int main()
{
   return 0;
}