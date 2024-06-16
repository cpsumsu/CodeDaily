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
    long long countSubstrings(string s, char c) {
        long long k = 0;
        for (auto ch : s) if (ch == c) k++;
        return k * (k + 1) / 2;
    }
};
int main()
{
   return 0;
}