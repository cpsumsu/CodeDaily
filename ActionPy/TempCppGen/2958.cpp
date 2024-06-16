#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        
        for (int start = 0, end = 0; end < nums.size(); end++) {
          m[nums[end]]++;

          while (m[nums[end]] > k) {
            m[nums[start++]]--;
          }

          ans = max(ans, end - start + 1);
        }

        return ans;
    }
};

class Solution_b {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int overk = 0, start = 0;

        for (int end = 0; end < nums.size(); end++) {
          m[nums[end]]++;

          if (m[nums[end]] == k + 1) {
            overk++;
          }

          if (overk > 0) {
            m[nums[start]]--;
            if (m[nums[start]] == k)
              overk--;
            start++;
          }
        }

        return nums.size() - start;
    }
};
int main()
{
   return 0;
}