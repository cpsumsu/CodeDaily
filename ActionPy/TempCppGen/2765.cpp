#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] - nums[j - 1] == ((j - i + 1) % 2 == 0 ? 1 : -1))
                {
                    ans = max(ans, j - i + 1);
                }
                else
                    break;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}