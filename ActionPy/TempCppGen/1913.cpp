#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
    }
};

class Solution_b {
public:
    int maxProductDifference(vector<int>& nums) {
        int m1 = INT_MIN;
        int m2 = INT_MIN;
        int l1 = INT_MAX;
        int l2 = INT_MAX;

        for (auto &x : nums) {
            if (x > m1) {
                m2 = m1;
                m1 = x;
            } else if (x > m2) {
                m2 = x;
            } 

            if (x < l1) {
                l2 = l1;
                l1 = x;
            } else if (x < l2) {
                l2 = x;
            }
        }

        return (m1 * m2) - (l1 * l2);
    }
};