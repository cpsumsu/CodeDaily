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
    bool isok(string& a, string& b)
    {
        int i = 0;
        for (int j = 0; i < a.size() && j < b.size(); ++j)
            if (a[i] == b[j]) ++i;
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for (int i = 0; i < strs.size(); ++i)
        {
            int tmp = strs[i].size();
            for (int j = 0; j < strs.size(); ++j)
            {
                if (i != j && isok(strs[i], strs[j]))
                {
                    tmp = -1;
                    break;
                }
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
int main()
{
   return 0;
}