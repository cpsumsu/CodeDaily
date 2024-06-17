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
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<int> homo(114514, 0);
        for (int a : nums)
        {
            int s = 0;
            for (int i = a; i; i /= 10)
                s += i % 10;
            if (homo[s])
                ans = max(ans, homo[s] + a);
            homo[s] = max(homo[s], a);
        }
        return ans;
    }
};
int main()
{
   return 0;
}