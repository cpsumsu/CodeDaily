#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size());
        long long cnt = (word[0] - '0') % m, rm = cnt;
        if (cnt == 0) cnt = 1, ans[0] = 1;
        else cnt = 0;
        for (int i = 1; i < word.size(); ++i)
        {
            rm *= 10;
            long long res = (rm + word[i] - '0') % m;
            if (res == 0)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = 0;
            }
            rm = res;
        }
        return ans;
    }
};
// 3 6 9 12 15 18 21 24 27 30
int main()
{
   return 0;
}