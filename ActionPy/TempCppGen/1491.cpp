#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX, s = 0;
        for (int i = 0; i < salary.size(); ++i) mx = max(salary[i], mx), mn = min(salary[i], mn), s += salary[i];
        return (double)(s - mx - mn) / (double)(salary.size() - 2);
    }
};