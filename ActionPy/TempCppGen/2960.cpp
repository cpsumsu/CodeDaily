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
    int countTestedDevices(vector<int>& batteryPercentages) {
        int tests = 0;

        for (auto &x : batteryPercentages) {
            if (x - tests > 0) 
                tests++;
        }

        return tests;
    }
};
int main()
{
   return 0;
}