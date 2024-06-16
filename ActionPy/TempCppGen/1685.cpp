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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int N = nums.size();
        vector<int> more(N, 0);

        int sum = nums[0];
        for (int i = 1; i < N; i++) {

            more[i] = more[i - 1] + (nums[i] - nums[i - 1]) * i * 2;        
            sum += nums[i];         // accumulate the sum of array nums
        }

        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            ans[i] = sum - N * nums[i] + more[i];
        }

        return ans;
    }
};
int main()
{
   return 0;
}