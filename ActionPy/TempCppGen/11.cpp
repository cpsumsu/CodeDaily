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
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while(l < r)
        {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
int main()
{
   return 0;
}