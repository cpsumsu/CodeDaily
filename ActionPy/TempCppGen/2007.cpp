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
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        vector<int> ans;
        unordered_map<int,int> mp;
        sort(changed.begin(), changed.end());
        for (int i = 0;i < changed.size(); ++i) mp[changed[i]]++; 
        for (auto a : changed)
        {
            if (mp[a] == 0) continue;
            mp[a]--;
            if (mp[a * 2] == 0) return {};
            mp[a * 2]--;
            ans.push_back(a);
        }
        return ans;
    }
};
int main()
{
   return 0;
}