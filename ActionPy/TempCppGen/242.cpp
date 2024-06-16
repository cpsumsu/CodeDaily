#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
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