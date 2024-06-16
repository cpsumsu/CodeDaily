#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, n = s.size();
        for (auto ch : s) if (ch == '1') cnt1++;
        string ans = "";
        for (int i = 1; i < cnt1; ++i) ans += "1";
        for (int i = 0; i < n - cnt1; ++i) ans += "0";
        return ans + "1";
    }
};

class Solution_b {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, n = s.size();
        for (auto ch : s) if (ch == '1') cnt1++;
        return string(cnt1 - 1, '1') + string(n - cnt1, '0') + '1';
    }
};