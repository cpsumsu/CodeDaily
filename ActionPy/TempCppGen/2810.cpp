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
    string finalString(string s) {
        string ans = "";
        for (auto ch : s) 
            if (ch == 'i') 
                for (int i = 0; i < ans.size() / 2; ++i)
                    swap(ans[i], ans[ans.size() - 1 - i]);
            else
                ans+=ch;
        return ans;
    }
};
int main()
{
   return 0;
}