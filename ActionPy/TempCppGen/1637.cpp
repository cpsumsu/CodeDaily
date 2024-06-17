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
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int max_wid = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            int x = abs(points[i][0] - points[i + 1][0]);
            max_wid = max(max_wid, x);
        }

        return max_wid;
    }
};
int main()
{
   return 0;
}