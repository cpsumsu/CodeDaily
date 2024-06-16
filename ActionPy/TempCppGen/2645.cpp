#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int addMinimum(string word) {
        int k = 3, ans = 0;
        word = 'c' + word + 'a';
        // b -> cba -> (b - c + 2) = 1
        for (int i = 0; i < word.size() - 1;++i)
        {
            ans += (word[i + 1] - word[i] + 2) % k;
        }
        return ans;
    }
};