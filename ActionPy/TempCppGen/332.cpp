#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    // 用map對字典序進行排序
    unordered_map<string, map<string,int>> targets;
    bool dfs(int x, vector<string>& res)
    {
        if (res.size() == x + 1) return true;
        for (pair<const string, int>& target : targets[res[res.size() - 1]])
        {
            if (target.second > 0)
            {
                res.push_back(target.first);
                target.second--;
                if (dfs(x, res)) return true;
                res.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> ans;
        for (auto& t : tickets) targets[t[0]][t[1]]++;
        ans.push_back("JFK");
        dfs(tickets.size(), ans);
        return ans;
    }
};