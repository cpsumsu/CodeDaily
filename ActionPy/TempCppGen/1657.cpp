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
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> mp(26, 0), mp2(26, 0);
        unsigned int m1 = 0, m2 = 0;
        for (int i = 0; i < word1.size(); ++i)
        {
            mp[word1[i] - 'a']++;
            m1 |= 1 << (word1[i] - 'a');
        }
        for (int i = 0; i < word2.size(); ++i)
        {
            mp2[word2[i] - 'a']++;
            m2 |= 1 << (word2[i] - 'a');
        }
        sort(mp.begin(), mp.end());
        sort(mp2.begin(), mp2.end());
        for (int i = 0; i < 26; ++i)
            if (mp[i] != mp2[i]) return false;
        return m1 == m2;
    }
};
int main()
{
   return 0;
}