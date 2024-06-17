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
    bool isAnagram(string s, string t) {
        int N = s.size(), M = t.size();
        if (N != M) return false;

        vector<int> A(26, 0);
        for (int i = 0; i < N; i++) {
            A[s[i] - 'a']++;
            A[t[i] - 'a']--;
        }

        for (auto x : A)
            if (x) return false;
        return true;
    }
};
int main()
{
   return 0;
}