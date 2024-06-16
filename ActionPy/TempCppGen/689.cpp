#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;



class Solution_a {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> prefix;
        int sum = accumulate(nums.begin(),nums.begin() + k, 0);
        prefix.push_back(sum);
        // prefix
        for (int i = k; i < nums.size(); i++) 
        {
            sum += nums[i] - nums[i - k];
            prefix.push_back(sum);
        }
        // L and R
        int n = prefix.size();
        vector<int> L(n, 0),R(n, n - 1);
        for (int i = 1; i < n; ++i)
        {
            L[i] = L[i - 1];
            if (prefix[i] > prefix[L[i - 1]]) L[i] = i;
        }
        for (int i = n - 2; i >= 0; --i)
        {
            R[i] = R[i + 1];
            if (prefix[i] >= prefix[R[i + 1]]) R[i] = i;
        }
        
        // dp
        int mmax = 0;
        vector<int> ans(3 , 0);
        for (int i = k; i < n - k; ++i)
        {
            int res = prefix[i] + prefix[L[i - k]] + prefix[R[i + k]];
            if (mmax < res)
            {
                mmax = res;
                ans = {L[i - k], i, R[i + k]};
            }
        }
        return ans;
            
    }
};