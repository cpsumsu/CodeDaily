#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    string makeGood(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (toupper(s[i - 1]) == toupper(s[i]) && s[i - 1] - s[i] != 0) {
                s = s.substr(0, i - 1) + s.substr(i + 1);
                i = i - 2 > 0 ? i - 2 : 0;
            }
        }

        return s;
    }
};

class Solution_b {
public:
    string rp(string s, int i)
    {
        return s.substr(0, i - 1) + s.substr(i + 1, s.size() - i - 1);
    }
    string makeGood(string s) {
        bool ok = false;
        while(!ok)
        {
            ok = true;
            for (int i = 1; i <= s.size(); ++i)
            {
                char ch = s[i], p = s[i - 1];
                if (ch >= 'A' && ch <= 'Z')
                    if (p - 32 == ch)
                        s = rp(s, i), ok = false;
                if (ch >= 'a' && ch <= 'z')
                    if (p + 32 == ch)
                        s = rp(s, i), ok = false;
            }
        }
        return s;
    }
};