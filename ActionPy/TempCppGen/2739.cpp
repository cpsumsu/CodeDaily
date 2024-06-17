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
    int distanceTraveled(int mainTank, int additionalTank) {
        return mainTank * 10 + min((mainTank - 1) / 4, additionalTank) * 10;
    }
};
int main()
{
   return 0;
}