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
    int lengthOfLastWord(string s) {
        auto a = s.find_last_not_of(' ');     
        auto b = s.rfind(' ', a);
        return a - b;
    }
};;
int main()
{
   return 0;
}