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
    bool isIsomorphic(string s, string t) {
        vector<int> a(256, -1), b(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (a[s[i]] != b[t[i]])
                return false;
            a[s[i]] = b[t[i]] = i;
        }

        return true;
    }
};
int main()
{
   return 0;
}