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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& pt1 : points)
        {
            unordered_map<int,int> dis;
            for (auto& pt2 : points)
            {
                int d2 = ((pt1[0] - pt2[0]) * 
                (pt1[0] - pt2[0])) +
                ((pt1[1] - pt2[1]) *
                (pt1[1] - pt2[1]));
                ans += dis[d2]++ * 2;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}