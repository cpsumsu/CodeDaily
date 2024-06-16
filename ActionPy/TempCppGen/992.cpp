#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }

    int atmost(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        int start = 0, ans = 0;

        for (int end = 0; end < nums.size(); end++) {
            m[nums[end]]++;

            while (m.size() > k) {
                m[nums[start]]--;
                if (m[nums[start]] == 0)
                    m.erase(nums[start]);
                start++;
            }

            ans += (end - start) + 1;
        }

        return ans;
    }
};

class Solution_b {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0, start = 0, end = 0, cur = 0;
        unordered_map<int, int> m;

        while (end < nums.size()) {
            // 1. expand the window
            m[nums[end]]++;

            if (m[nums[end]] == 1) {
                k--;
            }

            // 2. move the left bound to right and reset contribution value `cur`
            if (k < 0) {
                cur = 0;
                m[nums[start]]--;
                start++;
                k++;
            }

            // 3. extract the left bound as duplicated element, also refresh the answer
            if (!k) {
                while (m[nums[start]] - 1 != 0) {
                    m[nums[start]]--;
                    start++;
                    cur++;
                }

                ans += cur + 1;
            }

            end++;
        }

        return ans;
    }
};
int main()
{
   return 0;
}