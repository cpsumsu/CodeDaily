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
    int countNicePairs(vector<int>& nums) {
        unordered_map<int64_t, int64_t> M;

        auto reverse = [](int val) -> int64_t {
            int64_t ret = 0;

            while (val) {
                ret = 10 * ret + (val % 10);
                val /= 10;
            }
            return ret;
        };

        for (auto &x : nums) {
            int64_t y = reverse(x) - x;

            M[y]++;
        }   

        int64_t cnt = 0;
        for (auto &[r, c] : M) {
            cnt += c * (c - 1) / 2;
        }

        return cnt % int64_t(1e9 + 7);
    }
};
int main()
{
   return 0;
}