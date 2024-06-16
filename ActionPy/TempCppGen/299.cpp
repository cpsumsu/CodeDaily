#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0, n = secret.size();
        unordered_map<char, int> m;
        int vis[1005] = {0};
        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i]) a++, vis[i]++;
            else m[secret[i]]++;
        }
        for (int i = 0; i < n; ++i)
            if (!vis[i] && m[guess[i]]) b++, m[guess[i]]--;
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};
int main()
{
   return 0;
}