#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(),0);
        sort(idx.begin(), idx.end(), [&](int a, int b)
        {
            return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
        });
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += (i % 2 == 0 ? aliceValues[idx[i]] : -bobValues[idx[i]]);
        }
        if (ans > 0) return 1;
        else if (ans < 0) return -1;
        return 0;
    }
};

class Solution_b {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> idx(201);
        int n = aliceValues.size();

        for (int i = 0; i < n; i++) 
            idx[aliceValues[i] + bobValues[i]].push_back(i);

        int cnt = 0, purity = 1;

        for (int i = 200; i >= 0; i--) {

            for (auto &x : idx[i]) {
                cnt += (purity ? aliceValues[x] : -bobValues[x]);
                purity = purity ? 0 : 1;
            }
        }

        return cnt == 0 ? 0 : (cnt > 0 ? 1 : -1);
    }
};
int main()
{
   return 0;
}