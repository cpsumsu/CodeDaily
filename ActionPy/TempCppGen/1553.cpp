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
    unordered_map<int,int> um;
    int dfs(int n)
    {
        if (um.count(n)) return um[n];
        int n2 = n % 2, n3 = n % 3;
        return um[n] = min(1 + n2 + dfs(n / 2), 1 + n3 + dfs(n / 3));
    }
    int minDays(int n) {
        um[1] = 1;
        um[2] = 2;
        return dfs(n);
    }
};
int main()
{
   return 0;
}