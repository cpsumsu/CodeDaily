#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;


class Solution_a {
public:
    int firstUniqChar(string s) {
        vector<int> A(26);

        for (auto &x : s)
            A[x - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            if (A[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};
int main()
{
   return 0;
}