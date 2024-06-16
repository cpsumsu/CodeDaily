#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;


class Solution_a {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n / 2; i > 0; --i)
        {
            int d = abs(cost[i * 2 - 1] - cost[i*2]);
            ans += d;
            cost[i - 1] += max(cost[i * 2 - 1], cost[i * 2]);
        }
        return ans;
    }
};
int main()
{
   return 0;
}