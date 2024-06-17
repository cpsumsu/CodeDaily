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
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), ans = -1;
        for (int i = 0; i < n; ++i)
        {
            bool isok = false;
            for (int j = 0; j < n; ++j)
            {
                if (i != j && grid[i][j] == 0)
                {
                    isok = true;
                    break;
                }
            }
            if (!isok) return i;
        }
        return -1;
    }
};

class Solution_b {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][ans])
                ans = i;
        }
        return ans;
    }
};
int main()
{
   return 0;
}