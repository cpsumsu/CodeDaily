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
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), pos = 0;
        vector<vector<int>> ret;

        // insert
        while (pos < n && intervals[pos][1] < newInterval[0]) {
            ret.push_back(intervals[pos]);
            pos++;
        }

        // merge
        while (pos < n && newInterval[1] >= intervals[pos][0]) {
            newInterval[0] = min(newInterval[0], intervals[pos][0]);
            newInterval[1] = max(newInterval[1], intervals[pos][1]);
            pos++;
        }

        ret.push_back(newInterval);

        // insert
        while (pos < n) {
            ret.push_back(intervals[pos]);
            pos++;
        }

        return ret;
    }
};

class Solution_b {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        if (n == 0) return {newInterval};

        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval[0], 
            [](vector<int> &a, int b) {
                return a[0] < b;
            }) - intervals.begin();

        intervals.insert(intervals.begin() + it, newInterval);
        vector<vector<int>> ret;

        for (auto &x : intervals) {
            if (ret.empty() || ret.back()[1] < x[0])
                ret.push_back(x);
            else
                ret.back()[1] = max(ret.back()[1], x[1]);
        }

        return ret;
    }
};
int main()
{
   return 0;
}