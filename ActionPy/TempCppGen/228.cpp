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
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            int j = i;

            while (j + 1 < n && nums[j] + 1 == nums[j + 1])
                j++;

            if (j > i) {
                ret.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            } else {
                ret.push_back(to_string(nums[i]));
            }

            i = j;
        }

        return ret;
    }
};
int main()
{
   return 0;
}