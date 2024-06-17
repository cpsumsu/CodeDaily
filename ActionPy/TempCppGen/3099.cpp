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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int p = x, s = 0;
        while(p > 0)
        {
            int i = p % 10;
            s += i;
            p /= 10;
        }
        return x % s == 0 ? s : -1 ;
    }
};
int main()
{
   return 0;
}