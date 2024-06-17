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
    bool halvesAreAlike(string s) {
        string vowel = "aeiouAEIOU";

        int cnt = 0;
        for (int i = 0; i < s.size() / 2; i++)
            cnt += vowel.find(s[i]) != string::npos;

        for (int i = s.size() / 2; i < s.size(); i++)
            cnt -= vowel.find(s[i]) != string::npos;

        return cnt == 0;
    }
};
int main()
{
   return 0;
}