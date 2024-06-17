#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
#include <unordered_set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <cassert>
#include <cmath>
#include <cstdint>
using namespace std;


class Solution_a {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto dp = vector<bool>(s.size()+1);
        dp[0] = true;
        for(int i = 1; i<=s.size();i++){
            for(auto word:wordDict){
                int ws = word.size();
                if(i-ws>=0 && s.substr(i-ws,ws) == word){
                    dp[i] = dp[i] || dp[i-ws];
                }
            }
        }
        return dp[s.size()];
    }
};
int main()
{
   return 0;
}