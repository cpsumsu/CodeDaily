#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() <= k) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ans = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0), n = cardPoints.size();
        int res = ans;
        for (int i = 1; i <= k ; ++i)
        {
            res += cardPoints[n - i] - cardPoints[k - i];
            ans = max(ans, res);
        }
        return ans;
    }
};